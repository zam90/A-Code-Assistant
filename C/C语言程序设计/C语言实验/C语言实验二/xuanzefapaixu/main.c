#include<stdio.h>
int main()
{
    int a[10],i,b=0,j,k;
	printf("请输入十个整数：");
	for(i=0;i<10;i++)
		scanf("%d",&a[i]);
	for(i=0;i<9;i++)
	{
                                k=i;
		for(b=i+1;b<10;b++)
        {	    if(a[b]>a[k])
			{k=b;}
		}
                         if(k!=i)
                         {j=a[i];a[i]=a[k];a[k]=j; }
	}

	printf("从大到小排序：");
	for(i=0;i<10;i++)
		printf("%d\t",a[i]);
	printf("\n");
}
