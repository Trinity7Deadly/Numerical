#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <complex.h>
#include <string.h>

// Lagrange Interpolation Math

/*

	 (x-x2)(x-x3)...(x-xn)           (x-x1)(x-x3)...
	------------------------ (y1) + ------------------ (y2) + ...
	(x1-x2)(x1-x3)...(x1-xn)         (x2-x1)(x2-x3)...
	
*/

// Least Square Method

/*

	A*numpts + B*(x0 + x1 + x2 + ...)  = y0 + y1 + y2 + ...
	A*(x0 + x1 + x2 + ...) + B*(x0^2 + x1^2 + x2^2 + ...) = x0*y0 + x1*y1 + x2*y2 + ...

*/
