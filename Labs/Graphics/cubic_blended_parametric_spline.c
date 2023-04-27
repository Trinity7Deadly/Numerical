#include "FPToolkit.c"
#include "linear_system_toolkit.c"

double A(double x) {
  return 1.0/6.0 - 1.0/2.0 * x + 1.0/2.0 * pow(x,2) - 1.0/6.0 * pow(x,3);
}

double B(double x) {
  return 2.0/3.0 - pow(x,2) + 1.0/2.0 * pow(x,3);
}

double C(double x) {
  return 1.0/6.0 + 1.0/2.0 * x + 1.0/2.0 * pow(x,2) - 1.0/2.0 * pow(x,3);
}

double D(double x) {
  return 1.0/6.0 * pow(x,3);
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

// draws the open version of the graph
int make_open(double p[], double q[], int numpoints) {
  G_rgb(1, 0, 1) ;
  
  for(int i = 3; i < numpoints; i++) {
    for(double t = 0; t <= 1; t+= 0.01) {
    double xCord = A(t) * p[i-3] +
      B(t) * p[i-2] + C(t) * p[i-1] +
      D(t) * p[i] ;
    double yCord = A(t) * q[i-3] +
      B(t) * q[i-2] + C(t) * q[i-1] +
      D(t) * q[i] ;

    G_fill_circle(xCord, yCord, 1) ;
    }
  }
}

// draws the closed version of the graph
int make_closed(double p[], double q[], int numpoints){
  G_rgb(0, 1, 0) ;
  
  for(int i = 0; i < numpoints; i++) {
    for(double t = 0; t <= 1; t+= 0.01) {
    double xCord = A(t) * p[i] +
      B(t) * p[(i+1) % numpoints] +
      C(t) * p[(i+2) % numpoints] +
      D(t) * p[(i+3) % numpoints] ;
    double yCord = A(t) * q[i] +
      B(t) * q[(i+1) % numpoints] +
      C(t) * q[(i+2) % numpoints] +
      D(t) * q[(i+3) % numpoints] ;

    G_fill_circle(xCord, yCord, 1) ;
    }
  }
}

// dictates whether it will be drawn open or closed and sets up for it
int draw(double p[], double q[], int numpoints, int closed){
  G_rgb(0, 0, 0) ;
  G_clear() ;
  G_rgb(0, 0, 1) ;
  
  for(int i = 0; i < numpoints; i++) {
    G_fill_rectangle(p[i]-2, q[i]-2, 4,4) ; 
  }

  if(closed > 0) {
    make_closed(p, q, numpoints) ;
  } else {
    make_open(p, q, numpoints);
  }
}

int main() {
  double p[100], q[100] ;
  int numpts, i, key ;
  double xb, yb, numer, denom, m ;
  int closed = 1 ;

  G_init_graphics(800, 800) ;
  G_rgb(0, 0, 0) ; G_clear() ;

  numpts = click_save(p, q) ;

  if(numpts < 4) {
    printf("Please select at least 4 points \n") ;
    exit(0) ;
  }

  
  G_rgb(1, 0, 0) ;

  // commented math here...
  
  printf("%6.2f %6.2f %6.2f %6.2f \n", A(0), B(0), C(0), D(0)) ;
  
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

  // int xA = 0; 
  // int xB = 1;
  // for(int j = 1; j < numpoints; j++){
  //   for(int i = p[j-1]; i < p[j]; i ++){
  //     double y = q[j-1] + (q[j] - q[j-1])/(p[j] - p[j-1]) * (i - p[j-1]) + (x[xA] * (i - p[j-1]) * (i - p[j])) + (x[xB] * pow((i - p[j-1]), 2) * (i - p[j]));
  //     G_fill_circle(i, y, 1);
  //   }
  //   xA += 2;
  //   xB += 2;
  // }
