#include <stdio.h>

int main()
{
    int i=1,n=1;
    double pi=0;
    for(i=1;1.0/i>0.000001;i=i+2)
    {
        if(n%2!=0)
        {
            pi=(pi+1.0/i);
        }
        else if(n%2==0)
        {
            pi=(pi-1.0/i);
        }
        n++;
    }
    printf("Output:\nPI的近似值为:%.6lf",4*pi);
    return 0;
}
