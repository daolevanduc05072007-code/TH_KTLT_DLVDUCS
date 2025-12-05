#include<stdio.h>
#include<math.h>

#define EPS 1e-9
double a[5];

int main()
{
    scanf( "%lf %lf %lf" , &a[1], &a[2], &a[3] );

    if ( a[1] <= EPS || a[2] <= EPS || a[3] <= EPS )
    {
        printf("KHONG TAO THANH TAM GIAC !!!");
        return 0;
    }

    for ( int i=1 ; i <= 2 ; i++)   
        for ( int j=i+1 ; j <= 3; j++ )
        {
            double tmp = 0;
            if ( a[i] > a[j] )
            {
                tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
        }

    if ( a[1] + a[2] > a[3] + EPS )
    {
        if ( fabs(a[1] - a[2]) < EPS && fabs(a[2] - a[3]) < EPS )
        {
            printf("TAM GIAC DEU");
            return 0;
        }

        if ( fabs(a[1]*a[1] + a[2]*a[2] - a[3]*a[3]) < EPS )
        {
            if ( fabs(a[1] - a[2]) < EPS )
                printf( "TAM GIAC VUONG CAN" );
            else
                printf( "TAM GIAC VUONG" );
            return 0;
        }

        if ( a[1]*a[1] + a[2]*a[2] < a[3]*a[3] - EPS ) 
        {
            if ( fabs(a[1] - a[2]) < EPS || fabs(a[2] - a[3]) < EPS )
                printf("TAM GIAC TU CAN");
            else
                printf("TAM GIAC TU");
        }
        else
        {
            if ( fabs(a[1] - a[2]) < EPS || fabs(a[2] - a[3]) < EPS )
                printf("TAM GIAC NHON CAN");            
            else
                printf("TAM GIAC NHON");
        }
    }
    else
    {
        printf("KHONG TAO THANH TAM GIAC !!!");
    }
    
    return 0;
}
