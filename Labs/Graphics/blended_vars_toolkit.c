#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <complex.h>
#include <string.h>

double A(double x) {
  return 1.0/6.0 - 1.0/2.0 * x + 1.0/2.0 * pow(x,2) - 1.0/6.0 * pow(x,3);
}

double B(double x) {
  return 2.0/3.0 - pow(x,2) + 1.0/2.0 * pow(x,3);
}

double C(double x) {
  return 1.0/6.0 + 1.0/2.0 * x + 1.0/2.0 * pow(x,2) - 1.0/2.0 * pow(x,3);
}

double D(double x) {
  return 1.0/6.0 * pow(x,3);
}
