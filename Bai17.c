#include<stdio.h>
#include<math.h>
double x, y, z;

double max2( double x , double y )
{
    return  (x >= y) ? x : y;
}

double max3( double x, double y , double z )
{
    return max2( x , y ) >= z ? max2( x , y ) : z;
}

double min2( double x , double y )
{
    return  (x <= y) ? x : y;
}

int main()
{
    printf( "NHAP 3 SO X, Y, Z:   ");
    scanf( "%lf %lf %lf" , &x , &y , &z );
    printf( "max( x,y,z ) = %lf" , max3(x,y,z) );
    printf( "\nmax( x+y+z , xyz ) =  %lf " , max2(x+y+z,x*y*z));
    printf( "\nmin^2( x+y+z/2 , xyz ) + 1 = %lf" , min2(x+y+z/2 , x*y*z )*min2(x+y+z/2 , x*y*z ) + 1 );    

    

}
