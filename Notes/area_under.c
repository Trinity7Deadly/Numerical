#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <complex.h>
#include <string.h>

#define MAXDEGREE 30

int degree ;
double coef[100] ;

// User input of function
double f(double x) {
  double y = 0 ;

  for (int i = degree; i >= 0; i--) {
    y += coef[i] * pow(x, i) ;
  }
  
  return y ;
}

// Given function
double g(double x) {
  double y ;
  y = 4*(x*x*x) + 6*(x*x) - 8*x + 1 ;
  return y ;
}

// Allows user input of function
void setup(int degree) {
  double num ;
  int d = 1 ;
  
  for (int i = degree; i >= 0; i--) {
    printf("Coefficient %d: ", d) ;
    scanf("%lf", &num) ;
    coef[i] = num ;
    d++ ;
  }
}

// Riemann sum of the given function g(x)
double riemann(double a, double b, int n) {
  double sum = 0 ;
  double width = (b-a)/n ;

  for (int i = 0; i < n; i++) {
    sum = sum + f(a) ;
    a += width ;
  }
  sum = sum * width ;

  printf("Riemann's: %lf \n", sum) ;
}

double trapzoid(double a, double b, int n) {
  double sum = (f(a) + f(b))/2 ;
  double width = (b-a)/n ;

  for (int i = 1; i < n; i++) {
    a += width ;
    sum += f(a) ;
  }
  sum = sum * width ;

  printf("Trapazoid: %lf \n", sum) ;
}

double simpson(double a, double b, int n) {
  double sum = f(a) + f(b) ;
  double width = (b-a)/n ;
  double k ;

  for (int i = 1; i < n; i++) {
    a += width ;

    if (i%2 == 0) {
      sum = sum + 2*f(a) ;
    } else {
      sum = sum + 4*f(a) ;
    }
  }
  sum = (sum * width)/3 ;

  printf("Simpson's 1/3: %lf \n", sum) ;
}

int main() {
  double a, b ;
  int n ;

  printf("Enter Degree: ") ;
  scanf("%d", &degree) ;
  if (degree > MAXDEGREE) {
    printf("Too Big!\n") ;
    exit(0) ;
  }

  setup(degree) ;

  printf("Enter Left Point: ") ;
  scanf("%lf", &a) ;
  printf("Enter Right Point: ") ;
  scanf("%lf", &b) ;
  printf("Enter Number Divisions: ") ;
  scanf("%d", &n) ;

  riemann(a, b, n) ;
  printf("\n") ;
  trapzoid(a, b, n) ;
  printf("\n") ;

  //if n is even then simpson else enter even divisions for simpson

  simpson(a, b, n) ;
}
