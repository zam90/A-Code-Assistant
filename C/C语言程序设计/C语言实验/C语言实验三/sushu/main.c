#include <stdio.h>
#include <stdlib.h>

int main()
{
    void sushu(int a);
    int a;
    printf("请输入需要判断的数:\n");
    scanf("%d",&a);
    sushu(a);
    return 0;
}

void sushu(int a)
{
    int b,i;
    i=0;
    for(b=2;b<a;b++)
    {
        if(a%b==0)
        {
            i++;
        }
    }
    if(i==0)
    {
        printf("该数是素数\n");
    }
    else
    {
        printf("该数不是素数\n");
    }
}
