#include <stdio.h>
#include <stdlib.h>
#include <math.h>



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

fraction fradd(fraction a, fraction b){
  fraction ta, tb, r;
  ta.n = a.n * b.d;
  ta.d = a.d * b.d;

  tb.n = b.n * a.d;
  tb.d = ta.d;

  r.n = ta.n + tb.n;
  r.d = tb.d;

  return reduce(r);
}

fraction frsub(fraction a, fraction b){
  fraction tb;
  tb.n = -1 * b.n;
  tb.d = b.d;

  return fradd(a, tb);
}

fraction frdiv(fraction a, fraction b){
  fraction flip;
  flip.n = b.d;
  flip.d = b.n;

  return frmul(a, flip);
}

int frcomp(fraction a, fraction b){
  // if a > b return 1
  // if a < b return -1
  // if they are equal return 0
  fraction ta, tb, r;
  ta.n = a.n * b.d;
  ta.d = a.d * b.d;

  tb.n = b.n * a.d;
  tb.d = ta.d;

  if(ta.n > tb.n){
    return 1;
  }
  else if(ta.n < tb.n){
    return -1;
  }
  else{return 0;}

  
}