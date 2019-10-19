#include <stdio.h>


int main()
{
    char a;
    printf("Input: ");
    scanf("%c",&a);
    printf("Output:\n");
    if(a<='Z'&&a>='A')
    {
        printf("%c",a+32);
    }
    else
    {
        printf("%c",a);
    }
    return 0;
}
