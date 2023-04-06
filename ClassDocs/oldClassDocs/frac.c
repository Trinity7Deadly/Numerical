#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Midterm Retake Material

typedef
long int
lint ;


typedef
struct {
lint n ;
lint d ;
}
fraction ;


lint gcd(lint a, lint b)
{
  if (a == 0) return b ;
  else if (b == 0) return a ;
  else if (b > a)  return gcd(a, b%a) ;
  else return gcd(a%b, b) ;
}


fraction reduce(fraction x)
{
  fraction r ;
  lint g ;

  g = gcd(labs(x.n), labs(x.d)) ;

  
  r.n = x.n/g ;
  r.d = x.d/g ;

  if (r.d < 0) { r.d = -r.d ; r.n = -r.n ; }
  
  return r ;
}



fraction make_fraction(lint num, lint den)
{
  fraction r ;
  r.n = num ;
  r.d = den ;
  return reduce(r) ;
}



void print_fraction(char before[], fraction x, char after[])
{
  printf("%s[%ld/%ld]%s",before,x.n,x.d,after) ;
}




int iszero(fraction x)
{
  if (x.n == 0  && x.d != 0) return 1 ;
  return 0 ;
}



fraction frmul(fraction a, fraction b)
{
  fraction r ;
  r.n = a.n*b.n ;
  r.d = a.d*b.d ;
  return reduce(r) ;  
}

int main()
{
  fraction a,b,c ;
  a = make_fraction(6,9) ;
  b = make_fraction(20,40) ;
  c = frmul(a,b) ;

  print_fraction("c = ",  c,  "\n") ;
}
