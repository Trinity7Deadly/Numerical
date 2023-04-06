#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <complex.h>
#include <string.h>

#define MAXDEGREE 30
#define MAXITER 1000
#define EPSILON 1e-10

/*

Partially working code created using my synthetic division function as framework

*/

void prcmxedit(complex c) {
  double a, b ;
  a = creal(c) ;
  b = cimag(c) ;

  if (b >= 0) {
    printf("  +") ;
  } else {
    printf("  -") ;
  }
}

void durand_kerner(int degree, complex coef[], complex root[]) {
  int i, j;
  double delta = 2.0 * M_PI / degree;
  double angle = 0.0;

  complex complex_root[degree];

  for (i = 0; i < degree; i++) {
    complex_root[i] = cos(angle) + sin(angle) * I;
    angle += delta;
  }

  int iter;
  complex temp, f;
  double diff;
  for (iter = 0; iter < MAXITER; iter++) {
    diff = 0.0;
    for (i = 0; i < degree; i++) {
      f = 1.0 + 0.0 * I;
      for (j = 0; j < degree; j++) {
        if (i != j) {
          temp = complex_root[i] - complex_root[j];
          f *= temp;
        }
      }
      temp = coef[degree];
      for (j = degree-1; j >= 0; j--) {
        temp = coef[j] + temp * complex_root[i];
      }
      temp /= f;
      diff += cabs(temp);
      complex_root[i] -= temp;
    }
    if (diff < EPSILON) {
      break;
    }
  }

  for (i = 0; i < degree; i++) {
    root[i] = complex_root[i];
  }
}

int main() {
  int degree, i;
  printf("Enter Degree: ");
  scanf("%d", &degree);
  if (degree > MAXDEGREE) {
    printf("Too Big!\n");
    exit(0);
  }

  complex coef[degree+1], root[degree];
  for (i = degree; i >= 0; i--) {
    printf("Coefficient %d: ", degree-i+1);
    double rp;
    scanf("%lf", &rp);
    coef[i] = rp;
  }

  durand_kerner(degree, coef, root);

  for (i = 0; i < degree; i++) {
    printf("Root %d: %8.6lf", i+1, creal(root[i]));
    prcmxedit(root[i]);
    printf("%8.6lfI\n", cimag(root[i]));
  }

  return 0;
}
