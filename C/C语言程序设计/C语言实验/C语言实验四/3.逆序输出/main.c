#include <stdio.h>

int main()
{
    int n;
    printf("���������������ָ�����\n");
    scanf("%d",&n);
    printf("���������֣�\n");
    int a[n],i,num;
    for(i=0;i<n;i++)
    {
        scanf("%d",&num);
        char c=getchar();
        a[i]=num;
    }
    printf("����Ϊ��\n");
    for(i=n-1;i>=0;i--)
    {
        printf("%d ",a[i]);
    }
    return 0;
}
