#include "FPToolkit.c"

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

const double DELTA = 1e-13;


const int L = 20;


double f(double A, double B, double x){
  return A + B * x;
}



int printMatrix(double  mat[L][L], int n)
{

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n + 1; j++)
        {
	  printf("%10.6f \t", mat[i][j]);
        }
        printf("\n");
    }
}

int solveMatrix(double m[L][L], int n, double result[]){

  for(int i = n; i > 0; i--){
    double sum = 0;
    for(int j = 1; j <= n; j++){
      sum += result[j] * m[i][j];
    }
    result[i] = (m[i][n+1] - sum)/m[i][i];
  }
  return 1;
}

int triangularize(double m[L][L], int n){
  
  for(int i = 1; i < n; i++){
    for(int j = i+1; j <= n; j++){
	
      double max = 0;
      int loc = i;
      
      for(int k = i; k <= n; k++){
	if(m[k][i] > max){
	  max = m[k][i];
	  loc = k;
	}
      }


      double temp;
      for(int k = 1; k <= n+1; k ++){
        temp = m[i][k];
	m[i][k] = m[loc][k];
	m[loc][k] = temp;
      }

      double factor = m[j][i] / m[i][i];
      for(int c = 1; c <= n+1; c++){
	m[j][c] -= factor * m[i][c];
      }
    
    }
  
  }

  int flag = 0;
  for(int i = 1; i <= n; i++){
    if(fabs(m[n][i]) >= DELTA){
      flag++;
    }
  }

  if(flag == 0){
    
    if(fabs(m[n][n+1]) >= DELTA){
      printf("\nInconsistent");
      return 0;
    }
    else{
      printf("\nUnderdetermined");
      return -1;

    }
  }

  return 1;
}


int findAB(double x[], double y[], int numpoints){
  int n = 2;
  double mat[L][L];
  
  // build a 2x2 matrix
  double sum_of_Xs = 0;
  double sum_of_Ys = 0;
  double sum_of_sqXs = 0;
  double sum_of_XYs = 0;

  for(int i = 0; i < numpoints; i++){
    sum_of_Xs += x[i];
    sum_of_Ys += y[i];
    sum_of_sqXs += pow(x[i],2);
    sum_of_XYs += x[i] * y[i];
  }

  mat[1][1] = numpoints;
  mat[1][2] = sum_of_Xs;
  mat[1][3] = sum_of_Ys;
  
  mat[2][1] = sum_of_Xs;
  mat[2][2] = sum_of_sqXs;
  mat[2][3] = sum_of_XYs;
  
  
  printf("sum of Xs: %lf \n", sum_of_Xs);
  printf("sum of Ys: %lf \n", sum_of_Ys);
  printf("sum of square Xs: %lf \n", sum_of_sqXs);
  printf("sum of X*Ys: %lf \n", sum_of_XYs);

  printMatrix(mat, 2);

  triangularize(mat, 2);

  printMatrix(mat, 2);
  
  double result[2];
  solveMatrix(mat, 2, result);

  for(int i = 1; i <= 2; i++){
       printf("%10.2f", result[i]);
     }
     printf("\n");

     double A = result[0];
     double B = result[1];
      G_rgb(1,0,0);
      for(double x = 0; x < 800; x++){
	double y = f(A,B, x);
	G_fill_circle(x, y, 1);
	printf("%lf %lf \n",x,y);
    
	  }
  
  return 1;
}

int clickandsave(double x[], double y[])
{
  double xp,yp,p[2] ;
  int numpoints ;

  G_rgb(1, 0, 0) ; // red
  G_fill_rectangle(0,0 ,30,30) ;

  G_rgb(0.5,0.5,0.5) ;
  numpoints = 0 ;
  while (0 == 0) {

     G_wait_click(p) ;
     xp = p[0] ; yp = p[1] ;

     if ((xp >= 0) && (xp <= 30) && 
         (yp >= 0) && (yp <= 30))  { break ; }

     G_fill_rectangle(xp-2, yp-2, 4,4) ;     

     x[numpoints] = xp ; y[numpoints] = yp ; numpoints++ ;

  }

  return numpoints ;
}



int main()
{
  double x[100],y[100] ;
  int n,i ;
  double xb,yb,numer,denom,m ;

  G_init_graphics(800,800) ;
  G_rgb(0,0,0) ; G_clear() ;

  n = clickandsave(x,y) ;

  for(int i = 0; i < n; i++){
    printf("%lf %lf \n", x[i], y[i]);
  }

  findAB(x,y,n);
  //G_rgb(1,1,0) ;
  //G_fill_polygon(x,y,n) ;
 

  G_wait_key() ;
}
