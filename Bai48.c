#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdlib.h>
#define EPS 1e-6
double x;

double solve(double x)
{
    double y = x * M_PI / 180; 
    
    double temp = 1.0; 
    double sum = 1.0;
    int n = 1;

    while (fabs(temp) >= EPS)
    {
        temp = temp * (-1 * y * y) / ( (2 * n - 1) * (2 * n) );
        
        sum += temp;
        n++;
    }
    
    printf("S = Cos(%lf) = %.6lf\n", x, sum);
    
    return sum;
}

int main()
{
    printf( "Nhap x (do) : ");
    scanf( "%lf" , &x );
    solve(x);
    return 0; 
}
