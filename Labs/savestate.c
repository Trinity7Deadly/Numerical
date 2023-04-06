#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <complex.h>
#include <string.h>

// Lab 3

int setup(int row, double **matrix) {
  double temp ;
  int colm = row + 1 ;
  int j, i = 0 ;

  for (i = 0; i < row; i++) {
    j = 0 ;
    
    printf("Enter Coefficient x%dy%d: ", i, j) ;
    scanf("%lf", &temp) ;
    matrix[i][j] = temp ;
    
    for (j = 1; j < colm; j++) {
      printf("Enter Coefficient x%dy%d: ", i, j) ;
      scanf("%lf", &temp) ;
      matrix[i][j] = temp ;
    }
  }
  
  for (i = 0; i < row; i++) {
    for (j = 0; j < colm; j++) {
      printf("%8.6lf ", matrix[i][j]) ;
    }
    printf("\n") ;
  }
}

int main() {
  int num ;
  
  printf("Enter Size: ") ;
  scanf("%d", &num) ;
  
  double **matrix = (double **)malloc(num * sizeof(double *)) ;
  for (int i = 0; i < num; i++) {
    matrix[i] = (double *)malloc(num * sizeof(double)) ;
  }
  
  setup(num, matrix) ;
}
