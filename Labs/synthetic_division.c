#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <complex.h>
#include <string.h>
#include <stdbool.h>

#define MAXDEGREE 30

complex result[MAXDEGREE] ;
complex tempcoef[MAXDEGREE] ;

// Lab 2
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

complex NMpoly(int degree, complex coef[]) {

  complex x, top, bot;
  bool check;
  
  x = 1 + 2*I;
  
  for (int i = 0; i < 50; i++) {
    check = false ;
    top = synth(x, degree, coef, check) ;
    
    check = true ;
    bot = synth(x, degree-1, result, check) ;
    
    x = x - top/bot ;
  }
  
  return x ;
}

int main() {
  int degree ;
  complex remainder ;

  printf("Enter Degree: ") ;
  scanf("%d", &degree) ;
  if (degree > MAXDEGREE) {
    printf("Too Big!\n") ;
    exit(0) ;
  }

  complex coef[degree+1] ;
  complex roots[degree+1] ;

  setup(degree, coef) ;
  
  for (int i = 0; i < degree; i++) {
    roots[i] = NMpoly(degree-i, coef) ;
    //printf("Root %d: %8.6lf + %8.6lfI\n", i, creal(roots[i]), cimag(roots[i])) ;
    printf("Root %d: %8.6lf", i+1, creal(roots[i])) ;
    prcmxedit(roots[i]) ;
    printf("%8.6lfI\n", cabs(cimag(roots[i]))) ;
    
    for (int j = 0; j < degree-i; j++) {
      coef[j] = result[j] ;
    }
  }
	
}
