#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <complex.h>
#include <string.h>

int main() {
  double x = 1 ;
  for (int i = 0; i < 11; i++) {
    x = x * 2 ;
  }
  printf("%lf\n", x) ;
}

/*

What is 0.1 decimal to IEEE

	double to 0.2 no 1 to take away so double to 0.4 no 1 to take away
	double to 0.8 no 1 to take away so double to 1.6 take the 1 away then double .6
	to 1.2 then take out the 1 and double for 0.4 and so on.
	00011001100110011 etc.
	
	https://codinghero.ai/synthetic-division/
*/
