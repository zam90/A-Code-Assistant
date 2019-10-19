#include <stdio.h>

int main()
{
    int a,b,c;
    int hcf(int a,int b);
    printf("please input m,n:");
    scanf("%d,%d",&a,&b);
    c=hcf(a,b);
    printf("Output:\n%d",c);
    return 0;
}

int hcf(int a,int b)
{
    int z,i,h;
    if(a<=b)
    {
        z=a;
    }
    else
    {
        z=b;
    }
    for(i=z;i>0;i--)
    {
        if((a%i==0)&&(b%i==0))
        {
            h=i;
            break;
        }
    }
    return(h);
}
