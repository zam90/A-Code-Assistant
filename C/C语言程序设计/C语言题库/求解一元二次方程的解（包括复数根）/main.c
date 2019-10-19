#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    double a,b,c,der,x1,x2,x;
    printf("Please input a b c:\n");
    scanf("%lf %lf %lf",&a,&b,&c);
    der=b*b-4*a*c;
    if(a==0)
    {
        printf("Output:\nnot a quadratic");
    }
    else if(der>0)
    {
        x1=(-b-sqrt(der))/(2*a);
        x2=(-b+sqrt(der))/(2*a);
        printf("Output:\ndistinct real roots:\n%.4lf %.4lf",x1,x2);
    }
    else if(der==0)
    {
        x=(-b)/(2*a);
        printf("Output:\ntwo equal roots:\n%.4lf",x);
    }
    else if(der<0)
    {
        x1=b/-(2*a);
        x2=sqrt(-der)/-(2*a);
        printf("Output:\ncomplex roots:\n%.4lf+%.4lfi %.4lf-%.4lfi",x1,-x2,x1,-x2);
    }
    return 0;
}
