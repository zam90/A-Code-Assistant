#include <stdio.h>


int main()
{
    int a;
    printf("Please input a month number:\n");
    scanf("%d",&a);
    printf("Output:\n");
    if(a>=1&&a<=12)
    {
        if(a==1)
        {
            printf("This month's English name is January.");
        }
        if(a==2)
        {
            printf("This month's English name is February.");
        }
        if(a==3)
        {
            printf("This month's English name is March.");
        }
        if(a==4)
        {
            printf("This month's English name is April.");
        }
        if(a==5)
        {
            printf("This month's English name is May.");
        }
        if(a==6)
        {
            printf("This month's English name is June.");
        }
        if(a==7)
        {
            printf("This month's English name is July.");
        }
        if(a==8)
        {
            printf("This month's English name is August.");
        }
        if(a==9)
        {
            printf("This month's English name is September.");
        }
        if(a==10)
        {
            printf("This month's English name is October.");
        }
        if(a==11)
        {
            printf("This month's English name is November.");
        }
        if(a==12)
        {
            printf("This month's English name is December.");
        }
    }
    else
    {
        printf("Input Error!");
    }
    return 0;
}
