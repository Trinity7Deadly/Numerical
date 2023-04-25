#include "FPToolkit.c"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double A(double x){
  return 1.0/6.0 - 1.0/2.0 * x + 1.0/2.0 * pow(x,2) - 1.0/6.0 * pow(x,3);
}

double B(double x){
  return 2.0/3.0 - pow(x,2) + 1.0/2.0 * pow(x,3);
}

double C(double x){
  return 1.0/6.0 + 1.0/2.0 * x + 1.0/2.0 * pow(x,2) - 1.0/2.0 * pow(x,3);
}

double D(double x){
  return 1.0/6.0 * pow(x,3);
}

int clickandsave(double *x, double *y)
{
  double xp,yp,p[2] ;
  int numpoints ;

  G_rgb(1, 0, 0) ; // red
  G_fill_rectangle(0,0 ,30,30) ;

  G_rgb(0.5,0.5,0.5) ;
  numpoints = 0 ;
  while (0 == 0) {

     G_wait_click(p) ;
     xp = p[0] ; yp = p[1] ;

     if ((xp >= 0) && (xp <= 30) && 
         (yp >= 0) && (yp <= 30))  { break ; }

     G_fill_rectangle(xp-2, yp-2, 4,4) ;     

     x[numpoints] = xp ; y[numpoints] = yp ; numpoints++ ;

  }

  return numpoints ;
}


int drawOpen(double p[], double q[], int numpoints){
  G_rgb(1,0,0);
  for(int i = 3; i < numpoints; i++){
    for(double t = 0; t <= 1; t+= 0.01){
    double xCord = A(t) * p[i-3] + B(t) * p[i-2] + C(t) * p[i-1] + D(t) * p[i];
    double yCord = A(t) * q[i-3] + B(t) * q[i-2] + C(t) * q[i-1] + D(t) * q[i];

    G_fill_circle(xCord, yCord, 1);
    }
  }
}

int drawClosed(double p[], double q[], int numpoints){
  G_rgb(1,0,0);
  for(int i = 0; i < numpoints; i++){
    for(double t = 0; t <= 1; t+= 0.01){
    double xCord = A(t) * p[i] + B(t) * p[(i+1) % numpoints] + C(t) * p[(i+2) % numpoints] + D(t) * p[(i+3) % numpoints];
    double yCord = A(t) * q[i] + B(t) * q[(i+1) % numpoints] + C(t) * q[(i+2) % numpoints] + D(t) * q[(i+3) % numpoints];

    G_fill_circle(xCord, yCord, 1);
    }
  }
}


int draw(double p[], double q[], int numpoints, int closed){
  G_rgb(0,0,0);
  G_clear();

  G_rgb(0.5,0.5,0.5);
  for(int i = 0; i < numpoints; i++){
    G_fill_rectangle(p[i]-2, q[i]-2, 4,4) ; 
  }

  if(closed > 0){
    drawClosed(p, q, numpoints);
  }
  else{
    drawOpen(p,q,numpoints);
  }
}

int main()
{
  double p[100],q[100] ;
  int n,i ;
  double xb,yb,numer,denom,m ;


  int closed = 1;


  G_init_graphics(800,800) ;
  G_rgb(0,0,0) ; G_clear() ;

  n = clickandsave(p,q) ;


  int numpoints = n;

  if(numpoints < 4){
    printf("Please select at least 4 points \n");
    exit(0);
  }

  
  G_rgb(1, 0, 0);
  
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


  
  printf("%6.2f %6.2f %6.2f %6.2f \n", A(0), B(0), C(0), D(0));
  
  int c;
  while(True){
    draw(p,q, numpoints, closed);
    c = G_wait_key() ;

    if(c == 'c'){
      closed *= -1;

    }
    else if(c == 'q'){
      exit(0);
    }
  }
  
}
