#include <stdio.h>
#include <stdlib.h>
#include <math.h>


// Catastrophic cancellation is especially nasty for
// higher order derivatives



double p (double x)
{
  double y ;
  y = x*sin(x) ;
  return y ;
}


double p1_theory (double x)
{
  double y ;
  y = x*cos(x) + sin(x) ;
  return y ;
}


double p2_theory (double x)
{
  double y ;
  y = -x*sin(x) + 2*cos(x) ;
  return y ;
}


double p3_theory (double x)
{
  double y ;
  y = -x*cos(x) - 3*sin(x) ;
  return y ;
}



double p4_theory (double x)
{
  double y ;
  y = x*sin(x) - 4*cos(x) ;
  return y ;
}


/////////////////////////////////////



double q (double x)
{
  double y ;
  y = exp(x)/x ;
  return y ;
}


double q1_theory (double x)
{
  double y ;
  double x2 = x*x ;
  y = (1/x - 1/x2)*exp(x) ;
  return y ;
}



double q2_theory (double x)
{
  double y ;
  double x2 = x*x ;
  double x3 = x*x*x ;
  y = (2/x3 - 2/x2 + 1/x)*exp(x) ;
  return y ;
}


double q3_theory (double x)
{
  double y ;
  double x2 = x*x ;
  double x3 = x*x*x ;
  double x4 = x2*x2 ;
  y = (-6/x4 + 6/x3 - 3/x2 + 1/x)*exp(x) ;
  return y ;
}


double q4_theory (double x)
{
  double y ;
  double x2 = x*x ;
  double x3 = x*x*x ;
  double x4 = x2*x2 ;
  double x5 = x2*x3 ;
  y = (24/x5 - 24/x4 + 12/x3 - 4/x2 + 1/x)*exp(x) ;
  return y ;
}


/////////////////////////////////////


double h ;

double (*f)(double x) ;


double f1 (double x)
{
  double y ;
  y = (f(x+h) - f(x-h)) / (2*h) ;
  return y ;
}


double f2 (double x)
{
  double y ;
  y = (f1(x+h) - f1(x-h)) / (2*h) ;
  return y ;
}


double f3 (double x)
{
  double y ;
  y = (f2(x+h) - f2(x-h)) / (2*h) ;
  return y ;
}


double f4 (double x)
{
  double y ;
  y = (f3(x+h) - f3(x-h)) / (2*h) ;
  return y ;
}



int main()
{
  double x ;
  int i ;
  double t1,t2,t3,t4 ;
  double y1,y2,y3,y4 ;

  x = 2.5 ;


  ///////////////////////////////////////////////////////////////////////

  f = p ;
  t1 = p1_theory(x) ;
  t2 = p2_theory(x) ; 
  t3 = p3_theory(x) ;
  t4 = p4_theory(x) ;

  printf("theoretical :           %14e %14e %14e %14e\n", t1,t2,t3,t4) ;
  printf("------------------------------------------------------------------------\n") ;

  h = 0.1 ;
  for (i = 1 ; i <= 20 ; i++) {
    y1 = f1(x) ;
    y2 = f2(x) ;
    y3 = f3(x) ;
    y4 = f4(x) ;

    printf("%4d : %14e : %14e %14e %14e %14e\n",i, h, y1,y2,y3,y4) ;
    h = h/10 ;
  }
  printf("\n\n") ;

  ///////////////////////////////////////////////////////////////////////

  f = q ;
  t1 = q1_theory(x) ;
  t2 = q2_theory(x) ; 
  t3 = q3_theory(x) ;
  t4 = q4_theory(x) ;

  printf("theoretical :           %14e %14e %14e %14e\n", t1,t2,t3,t4) ;
  printf("------------------------------------------------------------------------\n") ;

  h = 0.1 ;
  for (i = 1 ; i <= 20 ; i++) {
    y1 = f1(x) ;
    y2 = f2(x) ;
    y3 = f3(x) ;
    y4 = f4(x) ;

    printf("%4d : %14e : %14e %14e %14e %14e\n",i, h, y1,y2,y3,y4) ;
    h = h/10 ;
  }
  printf("\n\n") ;

}


