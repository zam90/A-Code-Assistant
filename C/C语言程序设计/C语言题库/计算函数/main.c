#include <stdio.h>

int main()
{
    int x;
    printf("Input x: ");
    scanf("%d",&x);
    printf("Output:\n");
    if(x<1)
    {
        printf("%d",x);
    }
    if(x>=1&&x<10)
    {
        printf("%d",2*x-1);
    }
    if(x>=10)
    {
        printf("%d",3*x-11);
    }
    return 0;
}
