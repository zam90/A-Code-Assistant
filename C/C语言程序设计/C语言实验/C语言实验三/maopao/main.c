#include <stdio.h>

int main()
{
    int n,mid,min,i,j;
    printf("冒泡法排序\n请输入需排序数组的长度：");
    scanf("%d",&n);
    int a[n];
    printf("请输入长度为%d数组:\n",n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<n-1;i++)
    {
        int min=i;
        for(j=i+1;j<=n;j++)
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
    printf("该数组从小到大顺序为： \n");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}
