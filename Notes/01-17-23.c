#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
  double x[10] ;

  printf("Enter number of guesses: ") ;
  scanf("%lf", &x[0]) ;

  printf("Enter initial guess: ") ;
  scanf("%lf", &x[1]) ;
  
  for(int i = 1; i <= x[0]; i++) {
    //x[1] = cos(x[1])/2 ;
    //printf("%3d : %20.16lf \n", i, x[1]) ; //%e for scientific notation

    //x[1] = (pow(x[1], 3) - 36)/30 ;
    //printf("%3d : %20.16lf \n", i, x[1]) ;

    x[1] = (36/((pow(x[1], 2)) - 30)) ;
    printf("%3d : %20.16lf \n", i, x[1]) ;

    
  }
}
