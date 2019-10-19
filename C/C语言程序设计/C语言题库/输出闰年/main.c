#include <stdio.h>

int main()
{
    int i,d1,d2;
    printf("please input 2 datas: ");
    scanf("%d,%d",&d1,&d2);
    printf("output:");
    for(i=d1;i<=d2;i++)
    {
        if((i%4==0&&i%100!=0)||(i%400==0))
    {
        printf("\n%d",i);
    }
    }
    return 0;
}
