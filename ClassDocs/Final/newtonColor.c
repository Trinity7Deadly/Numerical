#include "FPToolkit.c"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <complex.h>

complex newCoef[100], secondCoef[100];

complex synthDiv(complex root, int degree, complex coef[], int second) {
	complex remainder = coef[0];
	
	for (int i=0; i<degree; i++) {
		if (second) {secondCoef[i] = remainder;}
		else {newCoef[i] = remainder;}
		remainder *= root;
		remainder += coef[i+1];
		//printf("%lf + %lf*I ",creal(coef[i+1]),cimag(coef[i+1]));
	}
	//printf("\n");
	return remainder;
}

complex newtonsMethod(int degree, complex coef[], complex x) {

  complex n, top, bottom;
  int second;
  n = x;
  
  for (int i = 0; i < 50; i++) {
    second = 0;
    top = synthDiv(n, degree, coef, second);
    second = 1;
    bottom = synthDiv(n, degree-1, newCoef, second);
    n = n - top/bottom;
    
    //printf("%lf + %lfI \n", creal(n), cimag(n));
  }
  return n;
}

int main() {
  double realCoef, color[100][3];
	complex startCoef[100], coef[100], roots[100], remainder, n, m;
	int degree, x, y, r;

	
	
	printf("\nWhat degree polynomial? \n");
	scanf("%d", &degree);
	for (int i = 0; i<=degree; i++) {
		printf("\nType coeffecient: \n");
		scanf("%lf", &realCoef);
		startCoef[i] = realCoef + 0*I;
		coef[i] = startCoef[i];
	}
	printf("\nWhat real number center?\n");
	scanf("%d", &x);
	printf("\nWhat imaginary number center?\n");
	scanf("%d", &y);
	printf("\nWhat radius?\n");
	scanf("%d", &r);
	

	G_init_graphics(800, 800);
	G_rgb(0,0,0) ; G_clear() ;

	for (int i = 0; i <= 800; i++) {
	  G_rgb(100,100,100);
	  G_circle(i, 400, .1);
	  G_circle(400, i, .1);
	}

	for (int i = 0; i<degree; i++) {
	  roots[i] = newtonsMethod(degree-i, startCoef, 1+2*I);
	  printf("%.3lf + %.3lf*I\n\n", creal(roots[i]), cimag(roots[i]));
	  color[i][0] = (drand48()+1.0)/2.0;
	  color[i][1] = (drand48()+1.0)/2.0;
	  color[i][2] = (drand48()+1.0)/2.0;
	  for (int j = 0; j<degree-i; j++) {
	    startCoef[j] = newCoef[j];
	  }
	}
	
	
	for (int i = x-r; i<=x+r; i++) {
	  for (int j = y-r; j<=y+r; j++) {
	    m = i + j*I;
	    printf("%.3lf + %.3lf*I\n\n", creal(n), cimag(n));
	    n = newtonsMethod(degree, coef, m);
	    
	    for (int k = 0; k <= degree; k++) {
	      printf("%.3lf + %.3lf*I\n\n", creal(roots[k]), cimag(roots[k]));
	      if (cabs(roots[k]-n)<0.001) {
		G_rgb(color[k][0], color[k][1], color[k][2]);
		G_circle(5*creal(m)+400, 5*cimag(m)+400, 2);
	      }
	    }
	      
	    printf("%.3lf + %.3lf*I\n\n", creal(n), cimag(n));
	    //G_circle(5*creal(n)+400, 5*cimag(n)+400, 2);
	    
	    
	  }
	}
	G_wait_key();
}
