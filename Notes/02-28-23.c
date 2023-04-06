#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <complex.h>
#include <string.h>

// Gauss-Seidel Method:
// It solves for each x, since what goes in becomes what comes out
int main() {
	double x1, x2, x3, x4 ;
	x1 = x2 = x3 = x4 = 0 ;
	
	for (int i = 1; i <= 15; i++) {
		x1 = (498 - 5*x2 - 8*x3 + 2*x4)/100 ;
		x2 = (834 - 4*x1 - 2*x3 - 6*x4)/200 ;
		x3 = (6 - 2*x1 - x2 - 4*x4)/10 ;
		x4 = (255 - 5*x1 - 15*x2 + 10*x3)/50 ;
		
		printf("%20.16lf, %20.16lf, %20.16lf, %20.16lf\n", x1, x2, x3, x4) ;
	}
}

/*

	w = [ 7 8 9 ]
	    [ 4 3 2 ]
	    [ 1 -9 5 ]

	Euclidean Norm:
	||w|| = sqrt(7^2 + 8^2 + 9^2 + 4^2 + 3^2 + 2^2 + 1^2 + -9^2 + 5^2)
	
	Max Row Sum:
	|7| + |8| + |9| = 24
	|4| + |3| + |2| = 9		max is 24
	|1| + |-9| + |5| = 14
	
	Max Colomn Sum:
	|7| + |4| + |1| = 12
	|8| + |3| + |-9| = 20		max is 20
	|9| + |2| + |5| = 16
	
	All three of these processes have the following four properties:
	(Properties of Norms)
		1. ||A|| >= 0 and ||A|| = 0 iff A = 0
		2. ||sA|| = |s| * ||A||
		3. ||A + B|| <= ||A|| + ||B||
		4. ||A * B|| <= ||A|| * ||B||
		
	Gauss-Seidel Method:
		xnew = c - m*xold
		
		error old = ||xold - x||
		error new = ||xnew - x||
		
		||(c - m*xold) - (c - m*x)||
		||-m(xold - x)||
		<= ||-m|| * ||xold - x||	property of norms
		|-1| * ||m|| * ||xold - x|| 	property of norms 2
		||m|| * error old
		error new <= ||m|| * error old
		error new <= (#<1) * error old
		The method is guaranteed to converge if the # is < 1
		
	Diagonally Dominant:
		- When the diagonal of a matrix of polynomials is greater then the added
		sum of the other number in a row then Gauss-Seidel Method will work.
		
		- Max row sum < 1 then converges & Gauss-Seidel
		
	

*/
