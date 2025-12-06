#include<stdio.h>
#include<math.h>
#include<stdlib.h>
double a[1000000],b[1000000], c[1000000];
int m, n;

int check( double a[] , int n , double x )
{
    for ( int i = 1 ; i <= n ; ++i )
        if ( a[i] == x )
            return 1;
    return 0;
}

void inp()
{
    printf("Nhap kich thuoc 2 tap hop A va B : ");
    scanf( "%d %d" , &m , &n );
    printf("Nhap phan tu tap hop A : ");
    int si = m;
    m = 0;
    for (int i = 1; i <= si; ++i) 
    {
        double temp;
        scanf("%lf", &temp);
        if (check(a, m, temp) == 0) 
        {
            m++;       
            a[m] = temp; 
        }
    }
    
    printf("Nhap phan tu tap hop B : " );
    si = n;
    n = 0;
    for (int i = 1; i <= si; ++i) 
    {
        double temp;
        scanf("%lf", &temp);
        if (check(b, n, temp) == 0) 
        {
            n++;       
            b[n] = temp; 
        }
    }
    return;
}

void outp( double c[] , int k )
{
    for ( int i = 1 ; i <= k ; ++i )
    {
        printf( "%lf " , c[i] );
        c[i] = 0 ;
    }
    printf("\n");
    return;
}
void phep_hop( double a[] , double b[] , int m , int n )
{
    int cnt = m;
    for ( int i = 1 ; i <= m ; ++i)
        c[i] = a[i];
    for ( int i = 1 ; i <= n ; ++i)
        if ( check( c , cnt , b[i] ) == 0 )
        {
            cnt++;
            c[cnt] = b[i];
        }
        
    outp( c , cnt );
    return;
}

void phep_giao( double a[] , double b[] , int m , int n )
{
    int cnt = 0;
    for ( int i = 1 ; i <= m ; ++i)
        for ( int j = 1 ; j <= n ; ++j )
            if ( a[i] == b[j] )
            {
                cnt++;
                c[cnt] = a[i];
            }
    outp( c , cnt );
    return;
}

void phep_hieu( double a[] , double b[] , int m , int n )
{       
    int cnt = 0;
    for ( int i = 1 ; i <= m ; ++i)
        if ( check( b , n , a[i] ) == 0 )
        {
            cnt++;
            c[cnt] = a[i];
        }
        
    outp( c , cnt );
    return;
}

void tap_con( double a[] , double b[] , int m , int n , int name )
{
    int cnt = 0;
    for ( int i = 1 ; i <= m ; ++i)
        for ( int j = 1 ; j <= n ; ++j )
            if ( a[i] == b[j] )
                cnt++;

    if ( cnt == m && name == 1)
    {
        if ( m == n )
            printf("A va B la tap con cua nhau\n");
        else
            printf("A la tap con cua B\n");
        return;
    }
    if ( cnt == m && name == 2)
        printf("B la tap con cua A\n");
    
    return;
}

void solve()
{
    printf("A hop B : ");
    phep_hop( a, b , m , n );
    printf("A giao B : ");
    phep_giao( a , b , m , n );
    printf("A hieu B : ");
    phep_hieu( a , b , m , n );
    printf("B hieu A : ");
    phep_hieu( b , a , n , m );
    if ( m <= n )
        tap_con( a , b , m , n , 1 );
    else
        tap_con( b , a , n , m , 2);

    
    
}

int main()
{
    inp();
    solve();

    return 0;
}
