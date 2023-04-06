#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// Newton's Method

int main() {
  double f, n, x ;

  printf("Enter Guess: ") ;
  scanf("%lf", &x) ;
  f = n = x;

  for (int i = 1; i <= 15; i++) {
    f = cbrt(30*f + 36) ;
    n = n - (n*n*n - 30*n - 36) / (3*n*n - 30) ;
    printf("%20.16lf, %20.16lf \n", f, n) ;
  }
}
