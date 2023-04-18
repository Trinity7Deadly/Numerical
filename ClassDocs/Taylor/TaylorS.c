#include <stdio.h>
#include <math.h>
#include <stdlib.h>


int Tdegree ;



int print_T (char before[], char control[], double t[], char after[])
// control is the control string for the doubles
// that will be printed
{
   int k ;

   printf("%s",before) ;
   printf("[") ;
   for (k = 0 ; k <= Tdegree ; k++) {
       printf(control,t[k]) ;
       if (k != Tdegree) { printf(",") ;}
   }
   printf("]") ;
   printf("%s",after) ;
   return 1 ;
}



int copy_T (double dest[], double source[])
{
  int k ;
  for (k = 0 ; k <= Tdegree ; k++) {
    dest[k] = source[k] ;
  }
  return 1 ;
}



int make_constant_T(double t[], double v)
{
  int k ;
  for (k = 0 ; k <= Tdegree ; k++ ) t[k] = 0 ;
  t[0] = v ;
  return 1 ;
}


int make_variable_T(double t[], double v)
// essentially makes a linear with value, v
{
  int k ;
  for (k = 0 ; k <= Tdegree ; k++ ) t[k] = 0 ;

  t[0] = v ;
  t[1] = 1 ;
  return 1 ;
}


//////////////////////////////////////////////////////////
// should be safe for any and all of these parameter
// pointers to point to same things



int Add_cons_T (double r[], double constant)
// r =  r + constant
{
  r[0] += constant ;
  return 1 ;
}



int Mul_cons_T (double r[], double constant)
// r =  r * constant
{
  int n ;

  for ( n = 0 ; n <= Tdegree ; n++ ) {
    r[n] *= constant ;
  }
  return 1 ;
}







int Add_T (double r[], double u[], double v[])
// r = u + v
{
  int k ;

  for (k = 0 ; k <= Tdegree ; k++ ) {
        r[k] = u[k] + v[k] ;
  }

  return 1 ;
}




int Sub_T (double r[], double u[], double v[])
// r = u - v
{
  int k ;

  for (k = 0 ; k <= Tdegree ; k++ ) {
      r[k] = u[k] - v[k] ;
  }

  return 1 ;
}



int Mul_T (double r[], double u[], double v[])
// r = u * v
{
  int n,k ;
  double sum ;
  double p[1000] ;

  for ( n = 0 ; n <= Tdegree ; n++ ) {

     sum = 0.0 ;
     for ( k = 0 ; k <= n ; k++ ) {
        sum = sum + u[k] * v[n-k] ;
     }

     p[n] = sum ;
  }
  
  copy_T (r,p) ;
  return 1 ;

}


