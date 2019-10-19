
// 201801140 3.cpp : Defines the entry point for the console application.
//

#include<stdio.h>
#include <stdarg.h>


int main()
{
	int a,b;//定义两个变量a，b
	float x,y;//定义两个变量x,y
	char c1,c2;//定义两个变量c1,c2
	scanf("a=%db=%d",&a,&b);//输入a,b
	scanf("%f%e",&x,&y);//输入x,y
	scanf("%c%c",&c1,&c2);//输入c1,c2
	printf("a=%d,b=%d\n",a,b);//输出a,b
	printf("x=%f,y=%f\n",x,y);//输出x,y
	printf("c1=%c,c2=%c\n",c1,c2);//输出c1,c2
	return 0;
}
