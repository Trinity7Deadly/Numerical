#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <complex.h>

void prcmxedit (complex c) {
  double a, b ;
  a = creal(c) ;
  b = cimag(c) ;
  
  if (b >= 0) {
    printf("  +") ;
    
  } else {
    printf("  -") ;
  }
  
}

int NMpoly() {
  complex temp, f, f1, x ;
  double rp, ip ;
  int degree ;
  
  printf("Enter: ") ;
  scanf("%d", &degree) ;
  
  complex coef[degree+1] ;
  int d = 1 ;
  
  for (int i = degree; i >= 0; i--) {
    printf("Coefficient %d: ", d) ;
    scanf("%lf", &rp) ;
    coef[i] = rp + 0*I ;
    d++ ;
  }

  printf("Enter Real Part: ") ;
  scanf("%lf", &rp) ;
  printf("Enter Imaginary Part: ") ;
  scanf("%lf", &ip) ;
  x = rp + ip*I ;

  for (int k = 1; k <= 30; k++) {
    f = 0 ; f1 = 0 ;
    
    for (int pow = degree; pow >= 0; pow--) {
    temp = coef[pow]*cpow(x, pow) ;
    f = f + temp ;

    temp = pow*coef[pow]*cpow(x, pow-1) ;
    f1 = f1 + temp ;
    }
    
    x = x - f/f1 ;
    printf("%d: %20.16lf", k, creal(x)) ;
    prcmxedit(x) ;
    printf("%20.16lfI \n", cabs(cimag(x))) ;
  }

}

int main() {
  NMpoly() ;
}

