#include "FPToolkit.c"

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
  G_rgb(0, 1, 0) ;
  for (double interval = 0; interval < 800; interval++) {
    double y_int = 0 ;
    
    for (int i = 0; i < numpts; i++) {
      double temp_var = y[i] ;
      
      for (int k = 0; k < numpts; k++) {
	if (k != i) {
	  temp_var *= (interval - x[k])/(x[i] - x[k]) ;
	  
	}
      }
      y_int += temp_var ;
    }
    G_fill_circle(interval, y_int, 1) ;
  }
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

  G_wait_key() ;
}
