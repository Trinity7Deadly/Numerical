#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/*----------------------------------------*\
| This is an example of a do-while loop.   |
| It does the test at the end of the loop. |
| This is the third type of loop.          |
| The others are for and while loops.      |
\*----------------------------------------*/
int scooby() {
  int i = 1 ;

  do {
    printf("%d \n", i) ;
    i++ ;
  } while (i <= 30) ;
  
}

int main() {
  double x[2] ;

  printf("Enter initial guess: ") ;
  scanf("%lf", &x[0]) ;

  for(int i = 0; i < 30; i++) {
    //x^2 - 2 = 0
    //x^2 - 4 = -2
    //x = 2 - 2/x+2
  }
}
