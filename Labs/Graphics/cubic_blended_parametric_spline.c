#include "FPToolkit.c"
#include "blended_vars_toolkit.c"

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

// draws the open version of the graph
int make_open(double p[], double q[], int numpts) {
  G_rgb(1, 0, 1) ;
  
  for(int i = 3; i < numpts; i++) {
    for(double t = 0; t <= 1; t += 0.01) {
    double xCord = A(t) * p[i-3] +
      B(t) * p[i-2] +
      C(t) * p[i-1] +
      D(t) * p[i] ;
    double yCord = A(t) * q[i-3] +
      B(t) * q[i-2] +
      C(t) * q[i-1] +
      D(t) * q[i] ;

    G_fill_circle(xCord, yCord, 1) ;
    }
  }
}

// draws the closed version of the graph
int make_closed(double p[], double q[], int numpts){
  G_rgb(0, 1, 0) ;
  
  for(int i = 0; i < numpts; i++) {
    for(double t = 0; t <= 1; t += 0.01) {
    double xCord = A(t) * p[i] +
      B(t) * p[(i+1) % numpts] +
      C(t) * p[(i+2) % numpts] +
      D(t) * p[(i+3) % numpts] ;
    double yCord = A(t) * q[i] +
      B(t) * q[(i+1) % numpts] +
      C(t) * q[(i+2) % numpts] +
      D(t) * q[(i+3) % numpts] ;

    G_fill_circle(xCord, yCord, 1) ;
    }
  }
}

// dictates whether it will be drawn open or closed and sets up for it
int draw(double p[], double q[], int numpts, int closed){
  G_rgb(0, 0, 0) ;
  G_clear() ;
  G_rgb(0, 0, 1) ;
  
  for(int i = 0; i < numpts; i++) {
    G_fill_rectangle(p[i]-2, q[i]-2, 4, 4) ; 
  }

  if(closed > 0) {
    make_closed(p, q, numpts) ;
  } else {
    make_open(p, q, numpts) ;
  }
}

// this is the main function...
int main() {
  double p[100], q[100] ;
  int numpts, i, key ;
  int closed = 1 ;

  G_init_graphics(800, 800) ;
  G_rgb(0, 0, 0) ; G_clear() ;

  numpts = click_save(p, q) ;

  if(numpts < 4) {
    int pts = 4 - numpts ;
    printf("You need %d more points\n", pts) ;
    exit(0) ;
  }
  
  G_rgb(1, 0, 0) ;
  
  //printf("%6.3f %6.3f %6.3f %6.3f \n", A(0), B(0), C(0), D(0)) ;
  
  while(True){
    draw(p, q, numpts, closed) ;
    key = G_wait_key() ;

    if(key == 'o') {
      closed *= -1 ;

    }
    else if(key == 'q') {
      exit(0) ;
    }
  }
  
}
