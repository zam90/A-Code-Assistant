#include <stdio.h>
#include <math.h>

int main()
{
    void convert(int n);
    int number;
    printf("����������: ");
    scanf("%d",&number);
    printf("ת��Ϊ: ");
    if(number<0)
    {
    putchar('-');
    putchar(' ');
    number=-number;
    }
    convert(number);
    printf("\n");
    return 0;
}

void convert(int n)
{
    int i;
    if((i=n/10)!=0)
    convert(i);
    putchar(n%10+'0');
    putchar(32);
}
