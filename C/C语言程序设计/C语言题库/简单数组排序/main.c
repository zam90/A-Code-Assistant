#include <stdio.h>

int main()
{
    int n,mid,min,i,j;
    printf("Please input n:");
    scanf("%d",&n);
    if(n>100)
    {
        printf("Output:Error!");
    }
    else
    {
        int a[n];
    printf("Please input %d numbers:",n);
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
    printf("Output:\nThe sort number is:");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    }

    return 0;
}
