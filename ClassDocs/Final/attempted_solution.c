#include "TaylorStudent.c"

// My first attempt at F1.c (doesn't work correctly)
int limit_attempt() {
  double x, y, top, bot ;

  x = 1.0 ;
  for (int i = 1; i <= 10; i++) {
    top = 17 + (14 - 8*cos(x) + cos(2*x)) * cos(2*x) - 24*cos(x) ;
    bot = (x*exp(x) - x) * (1 + 2*x*x - cos(2*x) - 4*x*sin(x)) ;
    
    y = top / bot ;

    printf("%16.12lf %16.12lf\n", x, y) ;

    x = x/2 ;
  }
}

// Possible solution
int limit_sol() {
  
}

// It's the main function...
int main() {
  limit_attempt() ;
}
