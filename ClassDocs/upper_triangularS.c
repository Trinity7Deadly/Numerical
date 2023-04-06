#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// Helps with Lab 3

int main()
{
  char fname[100] ;
  FILE *f ;
  double m[20][20] ;
  int n ;
  int r,c ;

  printf("enter the name of the file to be read : ") ;
  scanf("%s", fname) ;
  f = fopen(fname, "r") ;
  if (f == NULL) {
    printf("can't read file\n") ;
    exit(0) ;
  }
  
  fscanf(f,"%d",&n) ;
  for (r = 1 ; r <= n ; r++) {
    for (c = 1 ; c <= n+1 ; c++) {
      fscanf(f,"%lf", &m[r][c]) ;
    }
  }

  
  printf("\n") ;  
  for (r = 1 ; r <= n ; r++) {
    for (c = 1 ; c <= n+1 ; c++) {
      printf("%10.5lf", m[r][c]) ;
    }
    printf("\n") ;
  }  
  printf("\n") ;
  

}
