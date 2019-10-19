#include <stdio.h>

int main()
{
    int n;
    printf("请输入所输入数字个数：\n");
    scanf("%d",&n);
    printf("请输入数字：\n");
    int a[n],i,num;
    for(i=0;i<n;i++)
    {
        scanf("%d",&num);
        char c=getchar();
        a[i]=num;
    }
    printf("逆序为：\n");
    for(i=n-1;i>=0;i--)
    {
        printf("%d ",a[i]);
    }
    return 0;
}
