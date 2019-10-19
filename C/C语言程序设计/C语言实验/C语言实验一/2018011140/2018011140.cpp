// 2018011140.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include<math.h>


int main(int argc, char* argv[])
{
	double n,r,p;
	r=0.07;//给r赋值
	n=10;//给n赋值
	double m=pow(1+r,n);//调用函数，计算结果
	p=m*100;//小数百分数互换
	printf("假如我国国民生产总值的年增长率为7%%，计算10年后我国国民生产总值与现在相比增长多少百分比。\n");//提示语句
	printf("结果为%f%%\n",p);//显示结果
	return 0;
}
