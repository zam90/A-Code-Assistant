#include <stdio.h>

int main()
{
    int n,i;double r=0.0,s=1.0;
    printf("Input:\n");
    printf("Please input n:");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        s=s*i;
        r=r+1/s;
    }
    printf("Output:\nS=1/1!+1/2!+...+1/%d!=%.16f\n",n,r);
    return 0;
}
