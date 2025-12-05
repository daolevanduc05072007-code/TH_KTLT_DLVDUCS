#include<stdio.h>
#include<math.h>
#include<stdlib.h>
double a[10000000],b[10000000], c[10000000];
int m, n;
int cmp(const void *pa, const void *pb) 
{
    double a = *(const double*)pa;
    double b = *(const double*)pb;
    if (a > b) return -1;
    if (a < b) return 1;
    return 0;
}

void inp()
{
    printf("Nhap kich thuoc 2 mang A va B : ");
    scanf( "%d %d" , &m , &n );
    printf("Nhap mang A : ");
    for ( int i = 1 ; i <= m ; ++i )
        scanf( "%lf" , &a[i] );
    printf("Nhap mang B : " );
    for ( int i = 1 ; i <= n ; ++i )
        scanf( "%lf" , &b[i] );
}

void outp()
{
    for ( int i = 1 ; i <= m ; ++i )
        printf( "%lf " , a[i] );
    printf("\n");
    for ( int i = 1 ; i <= n ; ++i )
        printf( "%lf " , b[i] );
    printf("\n");
}

void solve()
{
    qsort(a+1,m,sizeof(double),cmp);
    qsort(b+1,n,sizeof(double),cmp);
    int i = 1, j = 1, k = 1;
    while ( i <= m && j <= n )
    {
        if ( a[i] >= b[j] )
            c[k++] = a[i++];
        else
            c[k++] = b[j++];
    }

    while ( i <= m )
        c[k++] = a[i++];
    while ( j <= n )
        c[k++] = b[j++];

    printf("\nMang A va B theo thu tu giam dan sau khi tron :\n");
    for (int i = 1; i <= m + n; ++i)
        printf("%lf ", c[i]);
    printf("\n");
    
    
}

int main()
{
    inp();
    outp();
    solve();


    return 0;
}
