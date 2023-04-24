#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <complex.h>
#include <string.h>

// Define long int as lint for later use
typedef
long int
lint ;

// Create a structure called fraction for later use
typedef
struct {
  lint n ;
  lint d ;
}
  fraction ;

// Prints the fraction in a legible format
void print_frac(char front[], fraction a, char back[]) {
  printf("%s[%ld/%ld]%s", front, a.n, a.d, back) ;
}

// Checks if the fraction is zero
int zero_frac(fraction a) {
  if (a.n == 0 && a.d != 0) {
    return 1 ;
  }
  return 0 ;
}

// Finds the greatest common denominator
lint greatestCD(lint a, lint b) {
  if (a == 0) return b ;
  else if (b == 0) return a ;
  else if (b > a)  return greatestCD(a, b%a) ;
  else return greatestCD(a%b, b) ;
}

// Reduces the fractoin using the greatestCD function
fraction reduce_frac(fraction a) {
  fraction frac ;
  lint temp ;

  temp = greatestCD(labs(a.n), labs(a.d)) ;

  frac.n = a.n/temp ;
  frac.d = a.d/temp ;

  if (frac.d < 0) {
    frac.d = -frac.d ;
    frac.n = -frac.n ;
  }

  return frac ;
}

// Creates a fraction
fraction create_frac(lint numerator, lint denominator) {
  fraction frac ;
  frac.n = numerator ;
  frac.d = denominator ;
  return reduce_frac(frac) ;
}

// Adds two fractions
fraction add_frac(fraction a, fraction b) {
  fraction tempA, tempB, temp ;

  tempA.n = a.n * b.d;
  tempA.d = a.d * b.d;

  tempB.n = b.n * a.d;
  tempB.d = tempA.d;

  temp.n = tempA.n + tempB.n;
  temp.d = tempB.d;

  return reduce_frac(temp) ;
}

// Subtracts two fractions
fraction subtract_frac(fraction a, fraction b) {
  fraction temp;
  temp.n = -1 * b.n;
  temp.d = b.d;

  return add_frac(a, temp);
}

// Multiplies two fractions
fraction mult_frac(fraction a, fraction b) {
  fraction temp;

  temp.n = a.n * b.n ;
  temp.d = a.d * b.d ;

  return reduce_frac(temp) ;
}

// Divides two fractions
fraction divide_frac(fraction a, fraction b) {
  fraction temp ;

  temp.n = b.d ;
  temp.d = b.n ;

  return mult_frac(a, temp) ;
}

// Compares the fractions
int compare_frac(fraction a, fraction b) {
  fraction tempA, tempB, temp ;

  tempA.n = a.n * b.d;
  tempA.d = a.d * b.d;

  tempB.n = b.n * a.d;
  tempB.d = tempA.d;

  if (tempA.n > tempB.n) {
    return 1 ;
  } else if (tempA.n < tempB.n) {
    return -1 ;
  } else {
    return 0 ;
  }
}
