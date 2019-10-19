// 1 to n sum.cpp : Defines the entry point for the console application.
//

#include<stdio.h>


int main()
{
	int i,c,sum;
	printf("1到n连续求和\n请输入数值n：");
	sum=0;
	scanf("%d",&c);
	for(i=1;i<=c;i++)
	sum=sum+i;
	printf("结果为:%d\n",sum);
	return 0;
}
