#include <stdio.h>

int main()
{
    int n,mid,min,i,j;
    printf("ð�ݷ�����\n����������������ĳ��ȣ�");
    scanf("%d",&n);
    int a[n];
    printf("�����볤��Ϊ%d����:\n",n);
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
    printf("�������С����˳��Ϊ�� \n");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}
