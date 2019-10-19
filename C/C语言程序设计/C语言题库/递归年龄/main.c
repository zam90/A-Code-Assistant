#include <stdio.h>

int main()
{
    int i,n,k,a;
    printf("Please input n k a:\n");
    scanf("%d %d %d",&n,&k,&a);
    for(i=0;i<n-1;i++)
    {
        a=a+k;
    }
    printf("Output:\nThe age is: %d.",a);
    return 0;
}
