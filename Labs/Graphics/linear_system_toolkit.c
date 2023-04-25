#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <complex.h>
#include <string.h>

int Read_Only = 0 ;

// Lab 3

// Manualy enter the matrix of values
int manual_setup(int row, double **matrix) {
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

  printf("\n") ;
  for (i = 0; i < row; i++) {
    for (j = 0; j < colm; j++) {
      printf("%8.6lf  ", matrix[i][j]) ;
    }
    printf("\n") ;
  }
}

// Reads the file that the user wants
int auto_setup(double ** m, int size, FILE * f) {
  int n ;
  int r,c ;
  
  n = size;
  for (r = 0 ; r < n ; r++) {
    for (c = 0 ; c < n+1 ; c++) {
      fscanf(f,"%lf", &m[r][c]) ;
    }
  }

  
  printf("\n") ;  
  for (r = 0 ; r < n ; r++) {
    for (c = 0 ; c < n+1 ; c++) {
      printf("%10.5lf  ", m[r][c]) ;
    }
    printf("\n") ;
  }  
  printf("\n") ;
}

// Swaps two rows
int row_swap(double * start, double * end) {
  double * temp = start ;
  start = end ;
  end = temp ;
}

// Adds two rows
int row_add(double * start, int columns, double * end, double adjust) {
  for (int c = 0; c < columns; c++) {
    start[c] += adjust * end[c] ;
  }
}

// Adjusts the row to cancel terms
int row_adjust(double * start, int columns, double adjust) {
  for (int c = 0; c < columns; c++) {
    start[c] *= adjust;
  }
}

// Makes adjustments to turn matrix into triagular matrix
void make_triangle(double * matrix[], int rows) {
  int columns = rows + 1 ;

  for (int r = 0; r < rows; r++) {
    if (matrix[r][r] == 0) {
      printf("possible divide by 0\n");
      for (int i = 1; i < rows; i++) {
	if (matrix[i][r] != 0) {
	  row_swap(matrix[r], matrix[i]) ;
	}
      }
    }
    printf("matrix[%d][%d]: %lf\n",r,r, matrix[r][r]);
    row_adjust(matrix[r], columns, 1/matrix[r][r]) ;
    for (int k = r + 1; k < rows; k++) {
      if (k > rows) { break ; }
      row_add(matrix[k], columns, matrix[r], -matrix[k][r]) ;
    }
  }
}

// Solves the triangular matrix and stores results
int solve_triangle(double ** matrix, int rows, double * solutions) {
  int columns = rows + 1 ;

  for (int r = rows - 2; r >= 0; r--) {
    for (int i = r; i >= 0; i--) {
      row_add(matrix[i], rows + 1, matrix[r+1], -matrix[i][r+1]) ;
    }
  }
  for (int k = 0; k < rows; k++) {
    printf("\t%lf\n",matrix[k][rows]) ;
    solutions[k] = matrix[k][rows] ;
  }
}

// Main functions where user selects how the matrix will be entered
int enter(int argc, char ** argv) {
  int num ;
  double solutions[20] ;
  char fname[100] ;
  FILE *f ;

  printf("Enter 0 for Manual and 1 for Automatic: ") ;
  scanf("%d", &Read_Only) ;

  if (Read_Only != 1) {
    printf("Enter Size: ") ;
    scanf("%d", &num) ;
  
    double **matrix = (double **)malloc(num * sizeof(double *)) ;
    for (int i = 0; i < num; i++) {
      matrix[i] = (double *)malloc(num * sizeof(double)) ;
    }
  
    manual_setup(num, matrix) ;

    make_triangle(matrix, num) ;
    solve_triangle(matrix, num, solutions) ;
    
  } else {
    printf("enter the name of the file to be read : ") ;
    scanf("%s", fname) ;
    f = fopen(fname, "r") ;
    
    //printf("opened file\n") ;
    
    if (f == NULL) {
      printf("can't read file\n") ;
      exit(0) ;
    }
  
    fscanf(f,"%d",&num) ;
    
    //printf("Scanned file\n") ;
    
    double **matrix = (double **)malloc(num * sizeof(double *)) ;
    for (int i = 0; i < num; i++) {
      matrix[i] = (double *)malloc(num * sizeof(double)) ;
    }
    //printf("Malloc complete\n");  
    auto_setup(matrix, num, f) ;
    
    //printf("auto_setup completed\n") ;
    
    make_triangle(matrix, num) ;  
    solve_triangle(matrix, num, solutions) ; 
  }

  for (int i = 0; i < num; i++) {
    printf("%6lf  ", solutions[i]) ;
  }
  printf("\n") ;
  
  //printf("BATMAN\n") ;
}

// solves a tri-diagonal system
int solve_tri_system (double L[], double D[], double R[], double Q[], int n, double x[]) {
  R[0] /= D[0] ;
  Q[0] /= D[0] ; 
  D[0] = 1 ;

  for(int i = 1; i < n; i++) {
    Q[i] = (Q[i] - L[i] * Q[i-1]) / (D[i] - L[i] * R[i-1]) ;	
    R[i] /= (D[i] - L[i] * R[i-1]) ;
    L[i] = 0 ;
    D[i] = 1 ;
  }
  
  x[n-1] = Q[n-1] ;
  for(int k = n - 2; k >= 0; k--) {
    x[k] = Q[k] - (x[k+1] * R[k]) ;
  }
  
  return 1 ;
}
