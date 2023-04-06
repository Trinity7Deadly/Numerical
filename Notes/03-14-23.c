#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <complex.h>
#include <string.h>

int main() {

}

/*

	Local Left Endpoint Riemann Sum (exact if linear combination of {1}) "constant"
	
	- Integral from x to x+h of f(t) dt is about h*f(x)
	- Applied repeatedly gives the Global Left Endpoint Riemann Sum
		- Integral from x0 to x1 of f(t)dt = hf0 + hf1 + ... + hfn-1
	
	Local Trapezoid (exact if function is a linear combination of {1, t})
	
	- Integral from x to x+h of f(t) dt = h{(f(x) + f(x+h))/2}
	- Applied repeatedly gives the Global Local Trapezoid
		- Integral from y0 to xn of f(t)dt is about h{(f0+f1)/2} + ... + h{(fn-1+fn)/2}
		
	Local Simpson's 1/3 Rule (exact if linear combination of {1, t, t^2}) "quadratics"
	
	- Integral from x-h to x+h of f(t)dt is about h{af(x-h) + bfx +cf(x-h)}
	- Applied repeatedly gives the Global Simpson's 1/3 Rule
		- (h/3){fo + 2[f2+f4+fb] + 4[f1+f3+f5+f7] + f8}

*/
