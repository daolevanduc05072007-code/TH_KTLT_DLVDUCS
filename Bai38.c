#include<stdio.h>
#include<math.h>
#define EPS 1e-12
double n;
long long N;

int main()
{
    scanf( "%lf" , &n );
    if ( fabs(n - round(n) ) > EPS )
    {
        printf( "%.12lf KHONG THUOC DAY FIBONACCI !!!" , n );
        return 0;
    }
    else
    {
        N = (long long) n; 
        long long x=0 , y = 1, z = 0;
        while ( z <= N )
        {
            if ( z == N )
            {
                printf( "%lld THUOC DAY FIBONACCI !!!" , N );
                return 0; 
            }
            z = x + y;
            x = y;
            y = z;
        }
        printf( "%lld KHONG THUOC DAY FIBONACCI !!!" , N );
    }

    

}
