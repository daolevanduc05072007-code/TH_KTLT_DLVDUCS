#include<stdio.h>
#include<math.h>
double a[5];

int main()
{
    printf("Nhap bo ba 3 canh cua tam giac: ");
    scanf( "%lf %lf %lf" , &a[1], &a[2], &a[3] );

    // ***SORT 3 SO NHANH GON LE*** // 
    for ( int i=1 ; i <= 2 ; i++)   
        for ( int j=i+1 ; j <= 3; j++ )
        {
            long long tmp = 0;
            if ( a[i] > a[j] )
            {
                tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
        }

    // ***FOR CHECK LAI SORT DUNG CHUA*** //
    //for ( int i=1 ; i <= 3 ; i++)   
        //printf( "%lld " , a[i]);

    // **SUM 2 CANH BE > CANH LON*** //
    if (  a[1] + a[2] > a[3] )
    {
        if ( a[1] == a[2] && a[2] == a[3] )
        {
            printf("TAM GIAC DEU");
            return 0;
        }
        if ( a[1]*a[1] + a[2]*a[2] == a[3]*a[3]  )
        {
            if ( a[1] == a[2] || a[2] == a[3] )
                printf( "TAM GIAC VUONG CAN" );
            else
                printf( "TAM GIAC VUONG" );
            return 0;
        }
        if ( a[1]*a[1] + a[2]*a[2] < a[3]*a[3] ) 
        {
            if ( a[1] == a[2] || a[2] == a[3]  )
                printf("TAM GIAC TU CAN");
            else
                printf("TAM GIAC TU");
        }
        else
        {
            if ( a[1] == a[2]  )
                printf("TAM GIAC NHON CAN");            
            else
                printf("TAM GIAC NHON");
        }


    }
    else
        printf("KHONG TAO THANH TAM GIAC !!!");
}
