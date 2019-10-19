#include <stdio.h>

int main()
{
    int n,s=1,i;
    printf("please input n:");
    scanf("%d",&n);
    if(n==0)
    {
        printf("Output:\n1");
    }
    else
    {
        for(i=1;i<=n;i++)
    {
        s=s*i;
    }
    printf("Output:\n%d",s);
    }
    return 0;
}
