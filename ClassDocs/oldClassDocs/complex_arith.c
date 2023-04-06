#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <complex.h>
#include <string.h>


void prcmx (char *control, complex c)
{
  double a,b ;
  a = creal(c) ;
  b = cimag(c) ;

  printf(control,a) ;
  if (b >= 0) {
    printf(" + ") ;
  } else {
    printf(" - ") ;
  }
  printf(control,fabs(b)) ;  
  printf("I") ;
}


complex sccmx ()
{
  double rp,ip ;
  complex c ;
  scanf("%lf %lf",&rp, &ip) ;
  c = rp + ip*I ;
  return c ;
}



int main()
{
  complex a,b,c,d,e,f,g,h ;
  double z ;

  a = 3 + 4*I ;
  b = 2 + 3*I ;
  c = a + b ;
  d = a - b ;
  e = a * b ;
  f = a / b ;
  g = csqrt(a) ;
  h = cpow(a,2) ;  
  z = cabs(a) ;
  
  printf("a         = ") ; prcmx("%20.16lf",a) ; printf("\n") ;
  printf("b         = ") ; prcmx("%20.16lf",b) ; printf("\n") ;
  printf("a + b     = ") ; prcmx("%20.16lf",c) ; printf("\n") ;
  printf("a - b     = ") ; prcmx("%20.16lf",d) ; printf("\n") ;
  printf("a * b     = ") ; prcmx("%20.16lf",e) ; printf("\n") ;
  printf("a / b     = ") ; prcmx("%20.16lf",f) ; printf("\n") ;
  printf("csqrt(a)  = ") ; prcmx("%20.16lf",g) ; printf("\n") ;
  printf("cpow(a,2) = ") ; prcmx("%20.16lf",h) ; printf("\n") ;    
  printf("cabs(a)   = %20.16lf\n",z) ;

  complex m ;
  printf("input real part and then imaginary part of a complex number ") ;
  m = sccmx() ;
  printf("m        = ") ;prcmx("%lf", m) ; printf("\n") ;  
  printf("csin(m)  = ") ;prcmx("%.16e", csin(m)) ; printf("\n") ;
}


