#include "fraction_math.c"

int MAX = 30 ;

// prints the matrix
int print_matrix(fraction frac[MAX][MAX], int power) {
  for (int i = 1; i <= power; i++) {
    for (int k = 1; k <= power + 1; k++) {
      print_frac("", frac[i][k], "");
    }
    printf("\n");
  }
}

// solves the matrix
int solve_matrix(fraction frac[MAX][MAX], int power) {
  printf("\n") ;
  printf("The Sum of %d Power: ", power-1);
  fraction result[power+1];
  for(int i = 0; i <= power; i++) {
    result[i] = create_frac(0,1);
  }
  
  for (int i = power; i > 0; i--) {
    fraction sum = create_frac(0, 1);
    for (int k = 1; k <= power; k++) {
      fraction frac2 = mult_frac(result[k], frac[i][k]);
      sum = add_frac(sum, frac2);
    }
    
    fraction frac3 = subtract_frac(frac[i][power + 1], sum);
    result[i] = divide_frac(frac3, frac[i][i]);
    if(i !=  1) {
      print_frac("", result[i], ""); printf("*n^%d + ", i);
    } else {
      print_frac("", result[i], ""); printf("*n^%d\n", i);
    }
  }
}

// moves around variables to create a trianglular matrix
int make_triangle(fraction frac[MAX][MAX], int power) {
  for (int i = 1; i < power; i++) {
    for (int k = i + 1; k <= power; k++) {
      fraction frac2 = create_frac(0, 1);
      int spare = i;

      for (int l = i; l <= power; l++) {
	if (compare_frac(frac[l][i], frac2) > 0) {
	  frac2 = frac[l][i];
	  spare = l;
	}
      }

      fraction temp;
      for (int l = 1; l <= power + 1; l++) {
	temp = frac[i][l];
	frac[i][l] = frac[spare][l];
	frac[spare][l] = temp;
      }
      
      fraction factor = divide_frac(frac[k][i], frac[i][i]);
      for (int m = 1; m <= power + 1; m++) {
	fraction frac3 = mult_frac(factor, frac[i][m]);
	frac[k][m] = subtract_frac(frac[k][m], frac3);
      }
    }
  }
  
  return 1;
}

// Finds the sum of the numerators
lint numerator_sum(int n, int power) {
  lint sum = 0 ;
  
  for (int i = 1; i <= n; i++) {
    sum += powl(i, power) ;
  }
  
  return sum ;
}

// Creates a matrix for the fractions
int create_matrix(fraction frac[MAX][MAX], int power) {
  int i;
  
  for (int y = 1; y <= power; y++) {
    for (int x = 1; x <= power; x++) {
      int power = powl(y,x) ;
      frac[y][x] = create_frac(powl(y, x), 1) ;
    }
  }
  
  for (int y = 1; y <= power; y++) {
    frac[y][power + 1] = create_frac(numerator_sum(y, power - 1), 1) ;
  }
  printf("\n") ;
  
  make_triangle(frac, power) ;
  print_matrix(frac, power) ;
  solve_matrix(frac, power) ;
}

// Does the main work of the function
int main() {
  fraction frac[MAX][MAX] ;
  int num = 3 ;
  int pow ;

  printf("Enter Power: ") ;
  scanf("%d", &pow) ;

  create_matrix(frac, pow+1);
  return 1;
}
