#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <complex.h>
#include <string.h>

// trying to create a riemann's sum program for any function from user input

int setup(int degree, complex coef[]) {
  double rp, ip ;
  int d = 1 ;
  
  for (int i = degree; i >= 0; i--) {
    printf("Coefficient %d: ", d) ;
    scanf("%lf", &rp) ;
    coef[i] = rp + 0*I ;
    d++ ;
  }
}

double f(double x) {
  double y ;

  for (int i = 0; i < degree+1; i++) {

  }

  return y ;
}

int main() {
  int degree ;
  
  printf("Enter Degree: ") ;
  scanf("%d", &degree) ;
  if (degree > MAXDEGREE) {
    printf("Too Big!\n") ;
    exit(0) ;
  }

  complex func[degree+1] ;

  setup(degree, func) ;
}
