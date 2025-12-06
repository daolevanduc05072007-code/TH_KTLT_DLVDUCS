#include <stdio.h>

long double tinh(double a,int n){
    long double tich=1;
    for (int i=0;i<n;i++){
        tich*=(a+1.0*i);
    }
    return tich;
}

long double tong_phan_so(long double a,int n ) {
    long double sum=0.0L;
    long double temp=1.0L;

    for (int i=0;i<=n;i++) {
        temp*=(a+i);
        sum+=1.0L/temp;
    }
    return sum;
}
int main(){
    double n;
    int N;
    double a;
    printf("Nhập vào số thực a và số nguyên n:");
    scanf("%lf %lf",&a,&n);
    
    if ( n != (long long)n ) {
        printf(" n phải là số nguyên (không chấp nhận số thập phân)!\n");
        return 0; 
    }
    N = (int) n;
    long double ket_qua_cau_a=tinh(a,N);
    printf("Kết quả câu a :%.10Lf\n",ket_qua_cau_a);
    
    //Tính câu b.
    //kiểm tra điều kiện
    for (int i=0;i<N;i++) {
        if (a+i==0) {
            printf("Mau so bang 0 tai a+%d\n",i);
            printf("Cau b khong thuc hien duoc.");
            return 0;
        }
    } 

    long double tong=tong_phan_so(a,N);
    printf("Kết quả câu b:%.10Lf",tong);

    return 0;
}
