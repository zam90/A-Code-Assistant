#include <stdio.h>

int main( )
{
    long a,b,c,d,e,x;
    printf("Input a data: ");
    scanf("%ld",&x);
    a=x/10000;        /*�ֽ����λ*/
    b=x%10000/1000;   /*�ֽ��ǧλ*/
    c=x%1000/100;     /*�ֽ����λ*/
    d=x%100/10;       /*�ֽ��ʮλ*/
    e=x%10;           /*�ֽ����λ*/
    printf("Output:\n");
    if (a!=0){
        printf("5\n%ld %ld %ld %ld %ld\n%ld %ld %ld %ld %ld",a,b,c,d,e,e,d,c,b,a);
    } else if(b!=0) {
        printf("4\n%ld %ld %ld %ld\n%ld %ld %ld %ld",b,c,d,e,e,d,c,b);
    } else if(c!=0) {
        printf("3\n%ld %ld %ld\n%ld %ld %ld",c,d,e,e,d,c);
    } else if(d!=0) {
        printf("2\n%ld %ld\n%ld %ld",d,e,e,d);
    } else if(e!=0) {
        printf("1\n%ld\n%ld",e,e);
    }
}
