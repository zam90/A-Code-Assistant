#include <stdio.h>

int main()
{
    int a[3],i,j,min,mid;
    printf("����������������");
    scanf("%d %d %d",&a[0],&a[1],&a[2]);
    for(i=0;i<2;i++)
    {
        min=i;
        for(j=i+1;j<=3;j++)
        {
            if(a[j]<a[min])
            {
                min=j;
            }
        }
        if(min!=i)
        {
            mid=a[i];
            a[i]=a[min];
            a[min]=mid;
        }
    }
    printf("��С��������Ϊ��%d %d %d",a[0],a[1],a[2]);
    return 0;
}
