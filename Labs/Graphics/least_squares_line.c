#include "FPToolkit.c"
#include "linear_system_toolkit.c"

double sols[2] ;

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

// Does the math
int math(double *x, double *y, int numpts) {
  double totalX, totalY ;
  double totalXY, powerX ;

  totalX = 0 ;
  totalY = 0 ;
  powerX = 0 ;
  totalXY = 0 ;

  double **matrix = (double **)malloc(2 * sizeof(double *)) ;
  for (int i = 0; i < 2; i++) {
    matrix[i] = (double *)malloc((3) * sizeof(double)) ;
  }
  
  for (int i = 0; i < numpts; i++) {
    totalX += x[i] ;
    totalY += y[i] ;
    powerX += x[i] * x[i] ;
    totalXY += x[i] * y[i] ;
  }

  matrix[0][0] = numpts ;
  matrix[0][1] = totalX ;
  matrix[0][2] = totalY ;
  matrix[1][0] = totalX ;
  matrix[1][1] = powerX ;
  matrix[1][2] = totalXY ;

  make_triangle(matrix, 2) ;
  solve_triangle(matrix, 2, sols) ;
}

// Main function
int main() {
  double x[100], y[100] ;
  int n, i ;
  double xb, yb, numer, denom, m ;

  G_init_graphics(800, 800) ;
  G_rgb(0, 0, 0) ; G_clear() ;

  n = click_save(x, y) ;

  math(x, y, n) ;

  for (int i = 0; i < 800; i++) {
    G_rgb(0, 1, 0) ;
    G_fill_circle(i, (sols[1]*i) + sols[0], 1) ;
  }

  G_wait_key() ;
}
