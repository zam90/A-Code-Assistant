#include <stdio.h>

int main()
{
    int a;
    printf("Input a year: ");
    scanf("%d",&a);
    printf("Output:\n");
    if((a%4==0&&a%100!=0)||(a%400==0))
    {
        printf("%d is leap year",a);
    }
    else
    {
        printf("%d is not leap year",a);
    }
    return 0;
}
