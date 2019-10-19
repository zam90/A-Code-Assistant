#include <stdio.h>

int main()
{
    int n,i,s=1;
    printf("Please input n: ");
    scanf("%d",&n);
    printf("Output:");
    for(i=1;i<=n;i++)
    {
        s=s*i;
        printf("\n%d!=%d",i,s);
    }
    return 0;
}
