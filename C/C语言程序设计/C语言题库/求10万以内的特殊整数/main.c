#include <stdio.h>

int main()
{
    int a,b,x,n;
    printf("Please input a number:");
    scanf("%d",&n);
    printf("Output:");
    for(a=1;a<=n;a++)
    {
        x=a*a-100;
        for(b=1;b<=n;b++)
        {
            if((b*b-268==x)&&(x<=n)&&(x>0))
            {
                printf("\n%d",x);
            }
        }
    }
    return 0;
}
