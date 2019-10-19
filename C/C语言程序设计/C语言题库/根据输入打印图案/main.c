#include <stdio.h>

int main()
{
    int i,n;
    printf("Please input n: ");
    scanf("%d",&n);printf("");
    printf("\n\n");
    printf("output:");
    for(i=1;i<=2*n-1;i++)
    {
        printf("$%i$\n");
    }
    return 0;
}
