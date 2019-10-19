#include <stdio.h>

int main()
{
    int n,i;double sn=0;
    int jc(int a);
    printf("Please input n:");
    scanf("%d",&n);
    printf("Output:\n");
    if(n>=1&&n<=10)
    {
        for(i=1;i<=n;i++)
    {
        sn=sn+jc(i);
    }
    printf("%.0lf",sn);
    }
    else
    {
        printf("Input error!");
    }
    return 0;
}

int jc(int a)
{
    int i;
    long long int z=1;
    for(i=1;i<=a;i++)
    {
        z=z*i;
    }
    return(z);
}
