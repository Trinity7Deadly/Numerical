#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// solve the tri-diagonal system :
// (in this example, the number of equations, n = 5)

// D0 R0               Q0
// L1 D1 R1            Q1
//    L2 D2 R2         Q2
//       L3 D3 R3      Q3
//          L4 D4      Q4




int tri_diagonal_solver (double L[],
                         double D[],
                         double R[],
                         double Q[],
			 int n,
                         double x[])
{
  R[0] /= D[0] ;
  Q[0] /= D[0] ; 
  D[0] = 1 ;

  for(int i = 1; i < n; i++) {
    Q[i] = (Q[i] - L[i] * Q[i-1]) / (D[i] - L[i] * R[i-1]) ;	
    R[i] /= (D[i] - L[i] * R[i-1]) ;
    L[i] = 0 ;
    D[i] = 1 ;
  }
  
  x[n-1] = Q[n-1] ;
  for(int k = n - 2; k >= 0; k--) {
    x[k] = Q[k] - (x[k+1] * R[k]) ;
  }
  
  return 1 ;
}



int main()
{
  int n ;
  double L[1000],D[1000],R[1000],Q[1000] ;
  double x[1000] ;
  int s, i ;

  
  //=======================================================================================
  // test case 1 :
  
  n = 0 ;
  D[n] =  1 ; R[n] =  2 ;                                           Q[n] = 11 ;   n++ ;
  L[n] =  2 ; D[n] =  7 ; R[n] =  1 ;                               Q[n] = 29 ;   n++ ;
              L[n] =  9 ; D[n] =  5 ; R[n] =  2 ;                   Q[n] = 33 ;   n++ ;
                          L[n] =  8 ; D[n] = 11 ; R[n] =  5 ;       Q[n] = 78 ;   n++ ;
                                      L[n] =  6 ; D[n] = 12 ;       Q[n] = 66 ;   n++ ;

  // the solution is 7,2,1,5,3

  s = tri_diagonal_solver (L,D,R,Q,n,x) ;

  if (s != 1) {
   printf("Could not find a unique solution.\n") ;
   exit(0) ;
  }

  printf("\nSolution to the triadiagonal system is :\n") ;
  for (i = 0 ; i < n ; i++) {
   printf("%lf\n",x[i]) ;
  }
  printf("\n") ;

  //=======================================================================================
  // test case 2 :
  
  n = 0 ;
  D[n] =  4 ; R[n] =  1 ;                                                       Q[n] = 14 ;   n++ ;
  L[n] =  2 ; D[n] =  5 ; R[n] =  2 ;                                           Q[n] = 24 ;   n++ ;
              L[n] =  3 ; D[n] =  1 ; R[n] =  2 ;                               Q[n] = 10 ;   n++ ;
                          L[n] =  6 ; D[n] =  4 ; R[n] =  2 ;                   Q[n] = 26 ;   n++ ;
                                      L[n] =  3 ; D[n] =  1 ; R[n] =  8 ;       Q[n] = 41 ;   n++ ;
                                                  L[n] =  3 ; D[n] =  4 ;       Q[n] = 23 ;   n++ ;

  // the solution is 3 2 4 0 1 5

  s = tri_diagonal_solver (L,D,R,Q,n,x) ;

  if (s != 1) {
   printf("Could not find a unique solution.\n") ;
   exit(0) ;
  }

  
  printf("\nSolution to the triadiagonal system is :\n") ;
  for (i = 0 ; i < n ; i++) {
   printf("%lf\n",x[i]) ;
  }
  printf("\n") ;						  
}
