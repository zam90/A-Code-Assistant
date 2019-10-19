#include <stdio.h>


int main()
{
    int a;
    printf("Please input a score: ");
    scanf("%d",&a);
    printf("Output:\n");
    if(a>=0&&a<=100)
    {
        if(a>=90)
        {
            printf("%d belongs to A",a);
        }
        if(a>=60&&a<=89)
        {
            printf("%d belongs to B",a);
        }
        if(a<60)
        {
            printf("%d belongs to C",a);
        }
    }
    else
    {
        printf("Input error!");
    }
    return 0;
}
