// 1 to n sum.cpp : Defines the entry point for the console application.
//

#include<stdio.h>


int main()
{
	int i,c,sum;
	printf("1��n�������\n��������ֵn��");
	sum=0;
	scanf("%d",&c);
	for(i=1;i<=c;i++)
	sum=sum+i;
	printf("���Ϊ:%d\n",sum);
	return 0;
}
