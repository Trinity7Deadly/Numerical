#include <stdio.h>
#include <math.h>


int main()
{
  double x,n,d,y ;
  int i ;

  x = 1.0 ;
  for (i = 1 ; i <= 10 ; i++) {


    n = 17 + (14 - 8*cos(x) + cos(2*x))*cos(2*x) - 24*cos(x) ;
    d = x*(exp(x) - 1)*(1 + 2*x*x - cos(2*x) - 4*x*sin(x)) ;
    y = n/d ;

    printf("%16.12lf  %16.12lf\n",x,y) ;

    x = x/2 ;
  }

}
