#include "FPToolkit.c"
#include "linear_system_toolkit.c"

// Takes the input from click_save and creates a tri_diagonal system
int create_tri_system(double L[], double D[], double R[], double TEMP[], int n, double p[], double q[]) {
  D[0] = 1 ;
  R[0] = -(p[1] - p[0]) ; 
  TEMP[0] = 0 ;

  for(int i = 1; i < n - 1; i++) {
    int dot = ceil((i+1) / 2) ;

    if(i % 2 == 0) {
      L[i] = pow((p[dot] - p[dot - 1]), 2) ;
      D[i] = -(p[dot+1] - p[dot-1]) ;
      R[i] = (p[dot] - p[dot-1]) * (p[dot+1] - p[dot]) ;
      TEMP[i] = -TEMP[i-1] ;
      
    } else {
      L[i] = p[dot] - p[dot-1] ;
      D[i] = pow((p[dot] - p[dot - 1]), 2) ;
      R[i] = p[dot + 1] - p[dot] ;
      TEMP[i] =  (q[dot+1] - q[dot])/(p[dot+1] - p[dot]) - (q[dot] - q[dot-1])/(p[dot] - p[dot-1]) ;
    }
  }

  int dot = ceil((n) / 2) ;
  L[n-1] = 1 ;
  D[n-1] = 2 * (p[dot] - p[dot - 1]) ;
  TEMP[n-1] = 0 ;
  
  return 0 ;
}

// Allows points to be clicked on screen
int click_save(double *x, double *y) {
  double xp, yp, p[2] ;
  int numpoints ;

  G_rgb(1, 0, 0) ;
  G_fill_rectangle(0, 0, 30, 30) ;

  G_rgb(0, 0, 1) ;
  numpoints = 0 ;

  while (0 == 0) {
    G_wait_click(p) ;
    xp = p[0] ; yp = p[1] ;

    if ((xp >= 0) && (xp <= 30) && 
	(yp >= 0) && (yp <= 30))  { break ; }

    G_fill_circle(p[0], p[1], 3) ;     

    x[numpoints] = xp ; y[numpoints] = yp ; numpoints++ ;

  }

  return numpoints ;
}

// Main section of the code
int main() {
  double p[100], q[100] ;
  double L[1000], D[1000], R[1000], TEMP[1000], x[1000] ;
  double tempA, tempB, tempC, y ;
  int numpoints, sol ;

  G_init_graphics(800,800) ;
  G_rgb(0,0,0) ; G_clear() ;

  numpoints = click_save(p,q) ;
  int size = (numpoints - 1) * 2 ;

  create_tri_system(L, D, R, TEMP, size, p, q) ;
  sol = solve_tri_system(L, D, R, TEMP, size, x) ;

  if (sol != 1) {
    printf("Could not find a unique solution.\n") ;
    exit(0) ;
  }
  
  for (int i = 0 ; i < size ; i++) {
    if (x[i] < 0) {
      printf("Tri-Diagonal Solution %d:   %lf\n", i+1, x[i]) ;
    } else {
      printf("Tri-Diagonal Solution %d:    %lf\n", i+1, x[i]) ;
    }
  }
  
  printf("\n") ;	
  G_rgb(0, 1, 0) ;
  
  int alpha = 0 ; 
  int beta = 1 ;
  for(int j = 1; j < numpoints; j++) {
    for(int k = p[j-1]; k < p[j]; k++) {
      tempA =  q[j-1] + (q[j] - q[j-1])/(p[j] - p[j-1]) * (k - p[j-1]) ;
      tempB = (x[alpha] * (k - p[j-1]) * (k - p[j])) ;
      tempC = (x[beta] * pow((k - p[j-1]), 2) * (k - p[j])) ;
      y = tempA + tempB + tempC ;
      
      G_fill_circle(k, y, 1) ;
    }
    
    alpha += 2 ;
    beta += 2 ;
  }
  
  G_wait_key() ;
}
