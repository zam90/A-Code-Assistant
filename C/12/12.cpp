#include <stdio.h>

int main()
{
    int n,i;
    double xh=100.0,h=100.0;
    printf("Please input n: ");
    scanf("%d",&n);
    printf("\n");
    printf("Output:\n");
    if(n<=0)
    {
        printf("Input error!");
    }
    else
    {
        for(i=1;i<=n;i++)
    {
        xh=xh*0.5;
        h=h+xh*2.0;
    }
    printf("�ܹ�����ĸ߶�Ϊ���ף�:%.3lf.\n",h);
    printf("��%d�ε���ĸ߶�Ϊ:%.3lf.",n,xh);
    }
    return 0;
}
