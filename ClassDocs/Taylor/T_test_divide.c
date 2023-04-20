#include "TaylorS.c"

double h = 1e-5 ;

double f (double x)
{
  double y ;
  y = (x*x*x - 2*x + 3)/(x*x + 1) ;
  return y ;
}

double f1 (double x)
{
  double y ;
  y = (f(x+h) - f(x-h))/(2*h) ;
  return y ;
}


double f2 (double x)
{
  double y ;
  y = (f1(x+h) - f1(x-h))/(2*h) ;
  return y ;
}


double f3 (double x)
{
  double y ;
  y = (f2(x+h) - f2(x-h))/(2*h) ;
  return y ;
}

double f4 (double x)
{
  double y ;
  y = (f3(x+h) - f3(x-h))/(2*h) ;
  return y ;
}


double f5 (double x)
{
  double y ;
  y = (f4(x+h) - f4(x-h))/(2*h) ;
  return y ;
}




int main()
//  Find the Taylor sequence for
//  (x*x*x - 2*x + 3) / (x^2 + 1)
//  with x = 0.75 through degree 5 
{
  double x = 0.75 ;
  double X[100],X2[100],X3[100],A[100],B[100],C[100],D[100] ;
  
  Tdegree = 5 ;

  make_variable_T (X, x)   ;
  
  Mul_T           (X2, X,X)  ; // X2 = X^2
  Mul_T           (X3, X2,X) ; // X3 = X^3 

  
  copy_T          (A, X3)    ; // A = X^3

  copy_T          (B,  X)    ; // B = X
  Mul_cons_T      (B,  2)    ; // B = 2X
  Sub_T           (A,  A,B)  ; // A = X^3 - 2X
  Add_cons_T      (A,  3)    ; // A = X^3 - 2X + 3

  copy_T          (C,  X2)   ; // C = X^2
  Add_cons_T      (C,  1)    ; // C = X^2 + 1


  Div_T           (D, A,C)   ; // D = (X^3 - 2X + 3)/(X^2 + 1)
  
  
  print_T("The answer is ", " %lf", D, "\n") ;
  
  printf("\nFinite diff   : ") ;
  printf("%lf  %lf  %lf  %lf  %lf  %lf\n",
	 f(x), f1(x), f2(x)/2, f3(x)/6, f4(x)/24, f5(x)/120 ) ;
  
}

