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




int Div_T (double r[], double u[], double v[])
// r = u / v
{
  int n,k ;
  double sum ;
  double q[1000] ;

  if (v[0] == 0.0)  {
    printf("\nTaylor Div_T:  v[0] is zero.\n") ;
    return 0 ;
  }

  q[0] = u[0] / v[0] ;

  for ( n = 1 ; n <= Tdegree ; n++ ) {

        sum = 0.0 ;
	for ( k = 0 ; k <= n - 1 ; k++ ) {
	     sum = sum + q[k] * v[n-k] ;
        }
        q[n] = (u[n] - sum) / v[0] ;

  }

  copy_T (r,q) ;
  return 1 ;
}








int exp_T (double r[],  double u[])
// r = exp(u)
{
  int  n,k ;
  double sum ;
  double E[1000] ;

  E[0] = exp(u[0]) ;

  for ( n = 1 ; n <= Tdegree ; n++ ) {

        sum = 0.0 ;
        for ( k = 0 ; k <= n-1 ; k++ ) {
           sum = sum + (n-k) * u[n-k] * E[k] ;
	}

	E[n] = sum / n ;
  }

  copy_T (r, E) ;
  return 1 ;
}





int ln_T  (double r[],  double u[])
// r = ln(u)
{
  int n,k ;
  double sum ;
  double L[1000] ;

  if (u[0] <= 0.0)  {
    printf("\nTaylor ln_T:  u[0] = %lf  needs to be positive.\n", u[0]) ;
    return 0 ;
  }

  
  L[0] = log(u[0]) ;
  
  for ( n = 1 ; n <= Tdegree ; n++ ) {

        sum = 0.0 ;
	for ( k = 1 ; k <= n - 1 ; k++ ) {
	     sum = sum + k * u[n-k] * L[k] ;
        }

	L[n] = (u[n] - sum / n) / u[0] ;

  }

  copy_T (r, L) ;
  return 1 ;
}






int cossin_T (double c[], double s[], double u[])
// c = cos(u) , s = sin(u)
{
  int n,k ;
  double ssum,csum ;
  double temp ;  
  double C[1000] ;
  double S[1000] ;

  C[0] = cos(u[0]) ;
  S[0] = sin(u[0]) ;

  for ( n = 1 ; n <= Tdegree ; n++ ) {

        csum = 0.0 ;  ssum = 0.0 ;
	for ( k = 0 ; k <= n - 1 ; k++ ) {
             temp = (n - k) * u[n-k] ;
             csum = csum + temp * S[k] ;
             ssum = ssum + temp * C[k] ;
	}

	C[n] = -csum / n ;	
	S[n] =  ssum / n ;
  }

  copy_T (c, C) ;
  copy_T (s, S) ;

  return 1 ;
}





int cos_T (double r[],  double u[])
{
 int sig ;
 double s[1000] ;

 sig = cossin_T (r,s,  u) ;

 return sig ;
}



int sin_T (double r[],  double u[])
{
 int sig ;
 double c[1000] ;

 sig  = cossin_T (c,r,  u) ;

 return sig ;
}




int tan_T (double r[],  double u[])
{
 int sig ;
 double c[1000] ;
 double s[1000] ;

 sig = cossin_T(c,s,  u) ;
 if (sig == 0) return 0 ;

 sig = Div_T (r,   s,c) ;
 if (sig == 0) return 0 ;

 return 1 ;
}






int sqrt_T (double r[],  double u[])
{
  int n,k ;
  double sum ;
  double p[1000] ;

  if ( u[0] == 0.0)  {
          printf("\nTaylor sqrt_T:  division by zero.") ;
	  return 0 ;
  } else   if ( u[0] < 0.0)  {
          printf("\nTaylor sqrt_T:  argument negative.") ;
	  return 0 ;
  }

  p[0] = sqrt(u[0]) ;

  for ( n = 1 ; n <= Tdegree ; n++ ) {
        sum = 0 ;
	for ( k = 1 ; k <= n-1  ; k++ ) {
           sum = sum + p[k] * p[n-k] ;
	}
 	p[n] = (u[n] - sum) / (2*p[0]) ;
  }

  copy_T (r,p) ;
  
  return 1 ;
}








int cpow_T (double r[], double u[], double cpow)
// p = u^c
// p' = c u^(c-1)u'
// up' = c u^c u'
// up' = c p u' ... continue from here
{
  int n,k ;
  double sum ;
  double p[1000] ;

  if ((Tdegree > 0) && (u[0] == 0.0))  {
     printf("\nTaylor cpow_T:  division by zero.") ;
     return 0 ;
  }

  p[0] = pow(u[0], cpow) ;
  
  for ( n = 1 ; n <= Tdegree ; n++ ) {

        sum = 0 ;
        for ( k = 1 ; k <= n-1  ; k++ ) {
	  sum = sum + ((cpow+1)*k - n) * u[k] * p[n-k] ;
	}
        
	p[n] = (cpow*n*p[0]*u[n] + sum) / (n*u[0]) ;

  }

  copy_T (r,p) ;
  
  return 1 ;


}







int atan_Tb (double r[],  double u[])
//  r = atan(u)
//  r' = u' / (1 + u^2)
//  (1+u^2)r' = u'
//  let w = u^2,  (1 + w)r' = u',
//  wr' = u'-r'  this is the key!!!

//  u'  - r'  = wr'
//  u'' - r'' = wr'' + w'r'
//  u''' - r''' =  wr''' + 2w'r'' + w'' r'
//  u'''' - r'''' = wr'''' + 3w'r''' + 3w''r'' + w'''r'
//  4!(u4 - r4)   = 4!w0r4 + 3*1!*3!w1r3 + 3*2!2!w2r2 + 3!w3r1
//  divide by 3! to get
//  4(u4 - r4)    = 4w0r4 + 3w1r3 + 2w2r2 + 1w3r1
//  now solve for r4 :
//  4u4 - {3w1r3 + 2w2r2 + 1w3r1} = 4w0r4 + 4r4
//  [4u4 - {3w1r3 + 2w2r2 + 1w3r1}] / (4*w0 + 4)  = r4 
{
  double w[1000], p[1000], sum ;
  int n,k ;
  
  Mul_T (w, u,u) ;

  p[0] = atan(u[0]) ;

  for (n = 1 ; n <= Tdegree ; n++) {

    sum = 0 ;
    for (k = 1 ; k <= n-1 ; k++) {
      sum += k*w[n-k]*p[k] ;
    }
    p[n] = (n*u[n] - sum) / (n*w[0] + n) ;

  }

  
  copy_T (r,p) ; 
  return 1 ;
}


