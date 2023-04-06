#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <complex.h>
#include <string.h>

int first() {
  double x ;

  for (x = 0.0; x < 1.0; x += 0.1) {
    printf("%lf\n", x) ;
  }
}

int second() {
  double x, y ;

  x = 0.1 ;
  y = x + x + x + x + x + x + x + x + x + x ;

  printf("%lf\n", y) ;

  if (y == 1) {
    printf("one\n") ;
  } else {
    printf("NOT one\n") ;
  }
}

int third() {
  unsigned int x, y, z ;
  x = 2000000000 ;
  y = 2000000000 ;
  z = x + y ;

  printf("%u %u %u\n", x, y, z) ;
}

/*

Computers don't like decimals! They work in binary, so a decimal 1.000 is the computer's approximation of 
a number close to binary 1. This means that there are some problems with the computer recognizing 1.0 as 1 
this is because 0.1 isn't perfectly convertable. The if statement can identify this, the print command cannot!

In "third" we use unsigned int to allow a number that would be too big to be printed to be printed.
100110101.1101
*/

int main() {
  //first() ;
  //second() ;
  //third() ;
}
