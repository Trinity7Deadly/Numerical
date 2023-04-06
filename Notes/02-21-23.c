#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <complex.h>
#include <string.h>

int main() {

}

/*

   - git clone <url>
   	- for pulling a file or folder from github
   - Partial pivoting
   	- Swap the current pivot row with the one that has the largest absolute value
   	- Designed to improve roundoff characteristics
   
   - Efficiency of Gaussion Elimination (lab3?)
   	- Row Reduction
   	- Back Substitution
   	- Example:
   	
   	    n = 5
   	    # # # # # | #
   	    # # # # # | #
   	    # # # # # | #
   	    # # # # # | #
   	    # # # # # | #
   	    
   	    R2 -> R2 - (6/2)R1 etc...
   	    until it is upper triangular
   	    
   	    # # # # # | #
   	    0 # # # # | # 
   	    0 0 # # # | #
   	    0 0 0 # # | #
   	    0 0 0 0 # | #
   	    
   	    (n(n+1)(2n+1))/6 - n
   	    
   	- Example 2:
   	    
   	    3*x1 + 7*x2 + 8*x3 + 9*x4 = 16	3 7 8 9 | 16
   	    4*x1 + 8*x2 + 4*x3 + 6*x4 = 12	4 8 4 6 | 12
   	    2*x1 + 6*x2 + 5*x3 + 2*x4 = 6	2 6 5 2 | 6
   	    3*x1 + 2*x2 + 4*x3 + 6*x4 = 9	3 2 4 6 | 9
   	    					   M	  b
   	    		Trying to find x's		   
   	    3 7 8 9 | 16	x1 = #
   	    0 # # # | #		x2 = #
   	    0 0 # # | # 	x3 = #
   	    0 0 0 # | # 	x4 = #
   	    				etc...
   	    Then plug back into the poly's to check solutions
   	    
   - Alternate Elimination Methods
   	- Find the inverse of a matrix and then use the inverse to find a solution
   	- The L U decomposition of M (too hard to type it, took picture)
   	- Then use the L & U in place of M in Mx = b
   		- LUx = b -> L(Ux) = b -> Ly = b solve for y (forward substitution)
   		- Then solve Ux = y for x (backward substitution)
   		- This method is nice because once broken down it can be used in different ways
   		- Issue is that it takes a little bit longer to compute
   	
   	

*/
