#include <stdio.h>

int main()
{
    int a,b,d;
    int lcd(int a,int b);
    printf("Please input a and b:");
    scanf("%d %d",&a,&b);
    if(a>0&&a<=1000&&b>0&&b<=1000)
    {
        d=lcd(a,b);
        printf("Output:%d",d);
    }
    else
    {
        printf("Output:\nInput error!");
    }
    return 0;
}

int lcd(int a,int b)
{
    int m,j,l;
    if(a>=b)
    {
        m=a;
    }
    else
    {
        m=b;
    }
    for(j=m;j<=a*b;j++)
    {
        if((j%a==0)&&(j%b==0))
        {
            l=j;
            break;
        }
    }
    return(l);
}
