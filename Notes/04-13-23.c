#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <complex.h>
#include <string.h>

// Differentiation Calculator thingy (not fully working!) Math is incorrect :(
// Working version in ClassDocs folder called finite_diff02.c :)

double simpsol[50] ;
double compsol[50] ;

// Given function
double f(double x) {
  double y ;
  y = x + sin(x) ;
  return y ;
}

// Does math shit for derivative
int simple_math(double x) {
  double deriv ;
  double h ;
  
  for (int i = 0; i < 20; i++) {
    h = 0.1 ;
    deriv = f(x+h) - f(x) ;
    deriv = deriv/h ;
    h = h/10 ;
    
    simpsol[i] = deriv ;
  }
}

// Does more math shit :(
int mad_math(double x) {
  double deriv ;
  double h ;
  
  for (int i = 0; i < 20; i++) {
    h = 0.1 ;
    deriv = f(x+h) - f(x-h) ;
    deriv = deriv/h ;
    h = h/10 ;
    
    compsol[i] = deriv ;
  }
}

// The main function
int main() {
  double x = 2.5 ;
  
  simple_math(x) ;
  mad_math(x) ;
  
  for (int i = 0; i < 20; i++) {
    printf("Simple Method: %lf | Complex Method: %lf \n", simpsol[i], compsol[i]) ;
  }
  
}
