#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <complex.h>
#include <string.h>
#include <stdbool.h>
#include "FPToolkit.c"

#define MAXDEGREE 30

int S_WIDTH, S_HEIGHT ;
complex result[MAXDEGREE] ;
complex tempcoef[MAXDEGREE] ;

// specified function
double f1 (double x) {
  double y ;
  y = (x*x*x*x) - 1 ;
  return y ;
}

// I got lazy and just did it manually
void setup_f1(complex coef[]) {
  coef[0] = 1 + 0*I ;
  coef[1] = 0 + 0*I ;
  coef[2] = 0 + 0*I ;
  coef[3] = 0 + 0*I ;
  coef[4] = -1 + 0*I ;
}

// Lab 2 stuff converted
void prcmxedit (complex c) {
  double a, b ;
  a = creal(c) ;
  b = cimag(c) ;
  
  if (b >= 0) {
    printf("  +  ") ;
    
  } else {
    printf("  -  ") ;
  }
  
}

// allows user input of function
void setup(int degree, complex coef[]) {
  double rp, ip ;
  int d = 1 ;
  
  for (int i = 0; i <= degree; i++) {
    printf("Coefficient %d: ", d) ;
    scanf("%lf", &rp) ;
    coef[i] = rp + 0*I ;
    d++ ;
  }
}

// synthetic division main part
complex synth(complex root, int degree, complex coef[], bool test) {
  complex remainder = coef[0] ;
	
  for (int i = 0; i < degree; i++) {
    if (test) {
      tempcoef[i] = remainder ;
    } else {
      result[i] = remainder ;
    }
    
    remainder *= root ;
    remainder += coef[i+1] ;
  }
  
  return remainder ;
}

// newton's method for polynomials secondary part
complex NMpoly(int degree, complex coef[], double rp, double ip) {
  complex z, top, bot;
  bool check;

  z = rp + ip*I;
  
  for (int i = 0; i < 50; i++) {
    check = false ;
    top = synth(z, degree, coef, check) ;
    
    check = true ;
    bot = synth(z, degree-1, result, check) ;
    
    z = z - top/bot ;
  }
  
  return z ;
}

// colors the segments
int color(double x, double y, complex z) {
  if (cabs(z - (1 + 0*I)) < 0.001) { G_rgb(1, 0.5, 0) ; }
  else if (cabs(z - (0 + 1*I)) < 0.001) { G_rgb(0, 1, 0.5) ; }
  else if (cabs(z - (-1 + 0*I)) < 0.001) { G_rgb(1, 0, 0.5) ; }
  else if (cabs(z - (1 - 1*I)) < 0.001) { G_rgb(0, 0.5, 1) ; }
  else { G_rgb(0, 0, 0) ; }
}

// main function to call shit
int main() {
  int degree, key ;
  double rp, ip ;
  complex remainder ;

  // user enters the radius
  int radius ;
  printf("Enter Radius: ") ;
  scanf("%d", &radius) ;

  S_WIDTH = 800; S_HEIGHT = 800;
  G_init_graphics(S_WIDTH, S_HEIGHT);
  G_rgb(0, 0, 0);
  G_clear();

  /*
  printf("Enter Degree: ") ;
  scanf("%d", &degree) ;
  if (degree > MAXDEGREE) {
    printf("Too Big!\n") ;
    exit(0) ;
  }
  */
  
  degree = 4 ;
  complex coef[degree+1] ;
  complex roots[degree+1] ;

  //setup(degree, coef) ;
  setup_f1(coef) ;

  // user input for point selection
  /*
  printf("Enter Real Part: ") ;
  scanf("%lf", &rp) ;
  printf("Enter Imaginary Part: ") ;
  scanf("%lf", &ip) ;
  */

  // allows clicks until quit
  while (key != 'q') {
  
    // click the screen for first guess
    double a, b, p[2] ;
    G_wait_click(p) ;
    
    a = (((p[0]-400)*radius)/400) + 400 ;
    b = (((p[1]-400)*radius)/400) + 400 ;
    rp = a ; ip = b ;
    
    complex z ;
    z = rp + ip*I;

    // does the root part of color
    NMpoly(degree-1, coef, rp, ip) ;
    color(p[0], p[1], z) ;
    G_fill_circle(p[0], p[1], 1) ;

    key = G_wait_key() ;
  }

  // finds all the roots from a guess
  /*
  for (int i = 0; i < degree; i++) {
    roots[i] = NMpoly(degree-i, coef, rp, ip) ;
    //printf("Root %d: %8.6lf + %8.6lfI\n", i, creal(roots[i]), cimag(roots[i])) ;
    printf("Root %d: %8.6lf", i+1, creal(roots[i])) ;
    prcmxedit(roots[i]) ;
    printf("%8.6lfI\n", cabs(cimag(roots[i]))) ;
    
    for (int j = 0; j < degree-i; j++) {
      coef[j] = result[j] ;
    }
  }
  */
}
