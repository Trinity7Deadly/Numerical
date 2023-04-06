#include <stdio.h>
#include <math.h>
#include <stdlib.h>


void print_coordinates(double x[], double y[], int numpoints)
{
  int i ;
  for (i = 0 ; i < numpoints ; i++) {
    printf("%3d : %24.16lf  %24.16lf\n", i, x[i], y[i]) ;
  }
}




// f points at a function with one double input and a double output 
int compute_values(double (*f)(double x), 
                   double left, double right,
		   int numgaps,
		   double x[], double y[])
// return the number of points
// the arrays x[] and y[] will hold the values of the computations
{
  double temp,dx,xvalue,yvalue ;
  int i ;
  
  if (numgaps < 1) return 0 ; // failure
  
  if (left > right) {
    temp = left ; left = right ; right = temp ;
  }

  dx = (right - left) / numgaps ;
  xvalue = left ;
  for (i = 0 ; i <= numgaps ; i++) {
    yvalue = f(xvalue) ;
    x[i] = xvalue ;
    y[i] = yvalue ;
    xvalue = xvalue + dx ;
  }

  return i ; 
}



double cube (double x)
{
  double y ;
  y = x*x*x ;
  return y ;
}


int main()
{
  double a[100] = {10.5, 20.7, 30.6} ;
  double b[100] = {82.5, 98.1, 68.1} ;
  print_coordinates(a,b,3) ;

  printf("-------------------------------------------\n") ;

  int numpoints,numgaps ;


  
  double p[50],q[50] ;
  numgaps = 2 ;
  numpoints = compute_values(sin,  -1.0, 1.0, numgaps,  p,q) ;
  print_coordinates(p,q, numpoints) ;

  printf("-------------------------------------------\n") ;  
  
  double u[200],v[200] ;
  numgaps = 10 ;
  numpoints = compute_values(cube,  2.0, 7.0, numgaps,  u,v) ;
  print_coordinates(u,v, numpoints) ;
  
}

