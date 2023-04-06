#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <complex.h>

int complexmathytime() {
  complex f, f1, x ;
  double rp, ip ;

  printf("Enter Real Part: ") ;
  scanf("%lf", &rp) ;
  printf("Enter Imaginary Part: ") ;
  scanf("%lf", &ip) ;
  x = rp + ip*I ;

  for (int i = 1; i <= 30; i++) {
    f = 3*(x*x*x) - 9*(x*x) + 32*x + 75 ;
    f1 = 9*(x*x) - 18*x + 32 ;
    x = x - f/f1 ;
    printf("%d: %20.16lf + %20.16lfI \n", i, creal(x), cimag(x)) ;
  }
}

int complextest() {
  complex a, b, c, d, e, f ;
  a = 3 + 4*I ;
  b = 2 + 3*I ;
  c = a + b ;
  d = a - b ;
  e = a * b ;
  f = a / b ;
  printf("a = %lf + %lfI \n", creal(a), cimag(a)) ;
  printf("b = %lf + %lfI \n", creal(b), cimag(b)) ;
  printf("c = %lf + %lfI \n", creal(c), cimag(c)) ;
  printf("d = %lf + %lfI \n", creal(d), cimag(d)) ;
  printf("e = %lf + %lfI \n", creal(e), cimag(e)) ;
  printf("f = %lf + %lfI \n\n", creal(f), cimag(f)) ;
  printf("abs(a) = %lf\n", cabs(a)) ;
  printf("abs(b) = %lf\n", cabs(b)) ;
  printf("abs(c) = %lf\n", cabs(c)) ;
  printf("abs(d) = %lf\n", cabs(d)) ;
  printf("abs(e) = %lf\n", cabs(e)) ;
  printf("abs(f) = %lf\n\n", cabs(f)) ;
}
/*
creal(a) = 3
cimag(a) = 4
cabs(a) = 5
csqrt(a)
 */

int mathymathtime() {
  double f, f1, x ;

  printf("Enter Guess: ") ;
  scanf("%lf", &x) ;

  for (int i = 1; i <= 30; i++) {
    f = 3*(x*x*x) - 17*(x*x) - 8*x + 112 ;
    f1 = 9*(x*x) - 34*x - 8 ;
    x = x - f/f1;
    printf("%d: %20.16lf \n", i, x) ;
  }

  double q, q1, y ;

  printf("\nEnter Guess: ") ;
  scanf("%lf", &y) ;

  for (int j = 1; j <= 30; j++) {
    q = 3*(y*y*y*y) - 29*(y*y*y) + 60*(y*y) + 144*y - 448 ;
    q1 = 12*(y*y*y) - 87*(y*y) + 120*y + 144 ;
    y = y - q/q1 ;
    printf("%d: %20.16lf \n", j, y) ;
  }
}

int main() {
  //complextest() ;
  //mathymathtime() ;
  complexmathytime() ;
}
