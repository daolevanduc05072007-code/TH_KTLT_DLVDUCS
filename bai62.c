#include <stdio.h>
#include <math.h>
//phan tich nhan tu
long long nhantu( long long n , int p ){
    long long dem=0;
    while ( n%p == 0 ){
        dem++;
        n /= p;
    }
    return dem;
}

int main(){
    int n;
    scanf ("%d", &n);
    long long dem2=0 , dem5=0;
   
    while ( n-- ){
        double x;
        scanf ("%lf", &x);
        if ( x != (long long) x || x < 0 )
        {
            printf( "khong phai so tu nhien !!!");
            return 0;
        }
        dem2 += nhantu( x , 2 );
        dem5 += nhantu( x , 5 );     
    }
    long long ketqua = ( dem2 < dem5 ) ? dem2 : dem5;
    printf ("%lld", ketqua );
    return 0;
}
