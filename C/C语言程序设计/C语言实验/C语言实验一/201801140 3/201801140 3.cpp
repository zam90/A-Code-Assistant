
// 201801140 3.cpp : Defines the entry point for the console application.
//

#include<stdio.h>
#include <stdarg.h>


int main()
{
	int a,b;//������������a��b
	float x,y;//������������x,y
	char c1,c2;//������������c1,c2
	scanf("a=%db=%d",&a,&b);//����a,b
	scanf("%f%e",&x,&y);//����x,y
	scanf("%c%c",&c1,&c2);//����c1,c2
	printf("a=%d,b=%d\n",a,b);//���a,b
	printf("x=%f,y=%f\n",x,y);//���x,y
	printf("c1=%c,c2=%c\n",c1,c2);//���c1,c2
	return 0;
}
