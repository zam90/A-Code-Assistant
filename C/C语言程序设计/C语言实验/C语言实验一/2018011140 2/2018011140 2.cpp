// 2018011140 2.cpp : Defines the entry point for the console application.
//

#include<stdio.h>

int main()
{
	char c1,c2;
	c1=97;//给c1赋值
	c2=98;//给c2赋值
	printf("c1=%c,c2=%c\n",c1,c2);//显示运行结果
	printf("c1=%d,c2=%d\n",c1,c2);//显示运行结果
	printf("运行结果如上所示\n");//提示语句
	printf("原因：使用不同的占位符\n");//提示语句
	printf("“%%c需输入单个字符，%%d需输入有符号的十进制整数”\n");//提示语句
	return 0;
}
