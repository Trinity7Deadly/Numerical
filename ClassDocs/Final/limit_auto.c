
#include <Taylor.h>
#include <stdio.h>

/* 

Use L'Hospital's rule to compute the limit of 


 17  +  [14 - 8*cos(x) + cos(2*x)] * cos(2*x)   - 24*cos(x)
------------------------------------------------------------
  [x*exp(x) - x] * [1 + 2*x*x - cos(2*x) - 4*x*sin(x)]


as x approaches 0


*/



// answer : 9/2


int limit()
{
  double x[100], twox[100] ;
  double Co[100],Si[100],Cotwo[100],Num[100],A[100] ;
  double B[100],C[100],D[100],Den[100] ;


  Tdegree = 10 ;

  make_variable_T(x, 0) ;

  cossin_T  (Co,Si,  x)  ; // Co = cos(x), Si = sin(x)

  copy_T(twox, x) ;
  Mul_cons_T(twox, 2) ;
  cos_T (Cotwo, twox) ;  // Cotwo = cos(2x)

  copy_T(Num,Co) ;
  Mul_cons_T(Num, -8) ;
  Add_cons_T(Num, 14) ;
  Add_T (Num,  Num, Cotwo) ; 
  Mul_T (Num,  Num, Cotwo) ;
  Add_cons_T(Num, 17) ;

  copy_T (A,Co) ;
  Mul_cons_T(A,-24) ;
  Add_T(Num,  Num,A) ; // Num = 17 + (14-8cos(x)+cos(2x))*cos(2x) - 24cos(x)

  ///////////////////////////////////////////////////////////////////////

  copy_T(B,  x) ;
  exp_T(B, B) ;
  Add_cons_T(B, -1) ;
  Mul_T(B, B,x) ;     // B = x(exp(x) - 1) = x*exp(x) - x

  copy_T(C, Si) ;
  Mul_T(C, C,x) ;
  Mul_cons_T(C, -4) ;
  Sub_T(C, C, Cotwo) ;
  Add_cons_T(C, 1) ; 

  Mul_T(D,  x,x) ;
  Mul_cons_T(D, 2) ;
  Add_T(C, C,D) ;     // C = 1 + 2x^2 - cos(2x) - 4x*sin(x)

  Mul_T(Den, B,C) ;   // Den = B*C

  printf("\n") ;
  print_T("Num = ", "%12.8lf\n", Num, "\n") ;
  printf("\n") ;
  print_T("Den = ", "%12.8lf\n", Den, "\n") ;

}




int main()
{
  limit() ;
}





