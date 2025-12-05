#include <stdio.h>
#include <math.h>

long double caua(long double a,int n) {
    //trường hợp 0 mũ 9
    if (a==0 && n==0) {
        printf("Khong xac dinh vì 0^0\n");
        return NAN;
    }

    //trường hợp n=0 và a!=0
    if (n==0 && a!=0) return 1.0L;

    //trường hợp a=0 và n>0
    if (a==0 && n>0) return 0.0L;

    //nếu n<0
    int test=0;
    if (n<0) {
        test=1;
        n=-n;
    }

    long double kq=expl(n*logl(fabs(a))); // dùng loga để tránh tràn số a^n=e^(n*lnA)

    if (a<0 &&(n%2==1)) kq=-kq;

    if (test) kq=1.0L/kq;

    return kq;
}

long double caub(long double a,int n) {
    long double tich2=1.0L;
    for (int i=0;i<n;i++) {
        tich2*=(a+i);
    }
    return tich2;
}

long double cauc(long double a,int n) {
    for (int i=0;i<n;i++) {
        if (a+i==0) {
            printf("Mau so bang 0 tai a+%d\n",i);
            printf("Cau c khong thuc hien duoc.");
            return NAN;
        }
    } 

    long double sum=0.0L;
    long double temp=1.0L;

    for (int i=0;i<=n;i++) {
        temp*=(a+i);
        sum+=1.0L/temp;
    }

    return sum;
}

int main() {
    double n;
    long double a;

    printf("Nhập vào số thực a và số nguyên n:\n");
    scanf("%Lf %lf",&a,&n);
    if ( n != (long long)n ) 
    {
        printf(" n phải là số nguyên (không chấp nhận số thập phân)!\n");
        return 0; 
    }
    n = (int) n;
    
    //Câu a.
    printf("Ket qua cau a:%Lf\n",caua(a,n));

    //Câu b.
    printf("Ket qua cau b:%Lf\n",caub(a,n));

    //Câu c.
    printf("Ket qua cau c:%Lf\n",cauc(a,n));

    return 0;
}
