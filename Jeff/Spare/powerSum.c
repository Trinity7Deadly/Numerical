#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#include "frac.c"

#define DELTA 1e-13

const int L = 20;

typedef long int
    lint;


int printMatrix(fraction mat[L][L], int n)
{

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n + 1; j++)
        {
            print_fraction("", mat[i][j], "");
        }
        printf("\n");
    }
}

int solveMatrix(fraction mat[L][L], int n)
{
    printf("Sum(k^%d) = ", n-1);

    fraction result[n+1];
    for(int i = 0; i <= n; i++){
        result[i] = make_fraction(0,1);
    }
    for (int i = n; i > 0; i--)
    {
        fraction sum = make_fraction(0, 1);
        for (int j = 1; j <= n; j++)
        {
            fraction tfrac = frmul(result[j], mat[i][j]);
            
            sum = fradd(sum, tfrac);
     
        }
        fraction t2 = frsub(mat[i][n + 1], sum);
	
        result[i] = frdiv(t2, mat[i][i]);
        if(i !=  1){
            print_fraction("", result[i], ""); printf("*n^%d + ", i);
        }
        else{
            print_fraction("", result[i], ""); printf("*n^%d\n", i);
        }
        
    }

}

int triangularize(fraction mat[L][L], int n)
{

    for (int i = 1; i < n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {

            fraction max = make_fraction(0, 1);
            int loc = i;

            for (int k = i; k <= n; k++)
            {
                if (frcomp(mat[k][i], max) > 0)
                {
                    max = mat[k][i];
                    loc = k;
                }
            }

            fraction temp;
            for (int k = 1; k <= n + 1; k++)
            {
                temp = mat[i][k];
                mat[i][k] = mat[loc][k];
                mat[loc][k] = temp;
            }
            fraction factor = frdiv(mat[j][i], mat[i][i]);
            for (int c = 1; c <= n + 1; c++)
            {
                fraction tfrac = frmul(factor, mat[i][c]);
                mat[j][c] = frsub(mat[j][c], tfrac);
            }
        }
    }

    
    return 1;
}

lint sumOfNs(int n, int p)
{
    lint sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += powl(i, p);
    }
    return sum;
}

int buildMatrix(fraction mat[L][L], int p)
{
    int i;

    for (int y = 1; y <= p; y++)
    {
        for (int x = 1; x <= p; x++)
        {   int power = powl(y,x);
            //printf("y = %d, x = %d, y^x = %d\t", y,x, power);
            mat[y][x] = make_fraction(powl(y, x), 1);
        }
        //printf("\n");
    }
    for (int y = 1; y <= p; y++)
    {
        mat[y][p + 1] = make_fraction(sumOfNs(y, p - 1), 1);
        ;
    }
    printf("\n");

    triangularize(mat, p);

    printMatrix(mat, p);

    solveMatrix(mat, p);
}

int main()
{
    fraction mat[L][L];

    int n = 3;
    int p;

    printf("Program finds a polynomial formula for Sum(k^p), enter p : ");
    scanf("%d", &p);


    buildMatrix(mat, p+1);
    return 1;
}
