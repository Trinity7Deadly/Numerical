


// Joe needs to evaluate the following integral :


//   _
//  / \  1
//  |
//   \       sin(2x)*ln(2 + cos(x))
//    \    -------------------------   dx
//     |       [ 3 + sin^2(x) ]^2
//     |
//     |
//  \_/  0 


// He plans to evaluate the integral by using Simpson's (1/3) rule with
// n = 10.  He also plans to compute the error bound. Joe recalls that
// this error bound requires that he bound the absolute value of the 
// 4-th derivative of the function being integrated over the region of
// integration (0 to 1 in this case).  

// Joe is not looking forward to the algebraic mess involved in computing
// the 4-th derivative, let alone in trying to bound it, so he decides
// to use Automatic Differentiation to compute the 4-th derivative at each
// of the points x = 0.0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0
// and compute his bound with these 11 values.  

// Implement Joe's plan, outputting both his estimate of the integral
// and his estimate of the error bound.


#include <Taylor.h>


double f (double x)
{
  double u,y ;
  u = 3+sin(x)*sin(x) ;
  y = sin(2*x)*log(2+cos(x))/(u*u) ;
  return y ;
}


double anti_f (double x)
{
  double y ;

  y =  (-1.0/16)*log(2 - cos(x)) + 
         (1.0/16)*log(2 + cos(x)) + 
            (-1.0/4)/(2 + cos(x)) -
              log(cos(x) + 2)/(3 + sin(x)*sin(x)) ;
  return y ;
}



double exact_integral(double a, double b)
{
  return  anti_f(b) - anti_f(a) ; 
}



double simpson_one_third_rule (double a, double b, int n)
{
  double h,x,osum,esum,s ;
  int i ;

  if (n %2 != 0) {
    printf("number of panels not even...value incremented\n") ;
    n = n + 1 ;
  }

  h = (b - a) / n ;

  osum = esum = 0.0 ;
  x = a ;
  for (i = 1 ; i <= n-2 ; i+=2) {
    x += h ;
    osum += f(x) ;
    x += h ;
    esum += f(x) ;
  }
  osum += f(b-h) ;
  
  s = (h/3)*(f(a) + f(b) + 4*osum + 2*esum) ;
  return s ;
}






double fourth_derivative(double t)
{
 double x[5],c[5],s[5] ;
 double E[5],F[5],G[5],H[5] ;

 Tdegree = 4 ;
 make_variable_T (x  , t) ; 

 cossin_T (c,s, x) ;

 copy_T     (E,  x)        ;     
 Mul_cons_T (E,  2)        ; 
 sin_T      (E,  E)        ; // E = sin(2x)

 copy_T     (F,  c)        ;     
 Add_cons_T (F,  2)        ; 
 ln_T       (F,  F)        ; // F = ln(2 + cos(x))

 Mul_T      (G,  s,s)      ; 
 Add_cons_T (G,  3)        ; 
 Mul_T      (G,  G,G)      ; // G = (3 + sin^2(x))^2

 Mul_T      (H,  E,F)      ;
 Div_T      (H,  H,G)      ; // H = sin(2x)*ln(2 + cos(x))/(3 + sin^2(x))^2

 return 24*H[4] ;
}


double M4(double a, double b, int n)
{
  int i ;
  double h,max,t,f4 ;

  h = (b - a) / n ;
  max = fabs(fourth_derivative(a)) ;
  for (i = 1 ; i <= n ; i++) {
    t = a + i*h ;
    f4 = fabs(fourth_derivative(t)) ;
    if (f4 > max) { max = f4 ; }
  }

  return max ;
}





int main()
{
  double a,b,E,S,Serr,Errbound ;
  int n ;

  a = 0 ; b = 1 ; 
  printf("a = %lf   b = %lf\n",a,b) ;
  E =  exact_integral(a,b) ; ;
  printf("The theoretical value = %20.16lf\n",E) ;

  n = 10 ;
  S = simpson_one_third_rule (a,b,n) ;
  Serr = S - E ;
  printf("Simpson (%d)          = %20.16lf\n",n,S) ;
  printf("Actual error          = %20.16lf\n",Serr) ;

  Errbound = M4(a,b,n)*(b-a)*pow((b-a)/n,4)/180 ;
  printf("Errbound              = %20.16lf\n",Errbound) ;  
}
