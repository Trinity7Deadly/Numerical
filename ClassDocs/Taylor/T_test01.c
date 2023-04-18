#include "TaylorS.c"



int main()
//  Find the Taylor sequence for
//  exp(2x) / (1 + x^2)
//  with x = 2.5 through degree 10.
{
  double x[100],A[100],B[100],C[100] ;

  Tdegree = 10 ;

  make_variable_T (x, 2.5)  ;
  copy_T          (A, x)    ; // A = x
  Mul_cons_T      (A, 2.0)  ; // A = 2x
  exp_T           (A, A)    ; // A = exp(2x)
  Mul_T           (B, x,x)  ; // B = x^2
  Add_cons_T      (B, 1.0)  ; // B = 1 + x^2
  Div_T           (C, A,B)  ; // C = exp(2x) / (1 + x^2)

  print_T("The answer is ", " %e", C, "\n") ;
}

