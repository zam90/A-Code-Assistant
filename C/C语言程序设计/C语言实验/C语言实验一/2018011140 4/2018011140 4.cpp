// 2018011140 4.cpp : Defines the entry point for the console application.
//

#include <stdio.h>


int main()
{
	int I;//定义I
	double p;//定义p
    I=0,p=0;//I，p赋值为0
	printf("请输入I: ");//提示语句
	scanf("%d",&I);//输入I
	if(I<=100000)//判断I是否<=100000
		p=I*0.1;//若是，则按此公式计算p
		else if(I<=200000)//若否，则判断I是否<=200000
			p=100000*0.1+(I-100000)*0.075;//若是，则按此公式计算p
		else if(I<=400000)//若否，则判断I是否<=400000
			p=100000*0.1+100000*0.075+(I-200000)*0.05;//若是，则按此公式计算p
		else if(I<=600000)//若否，则判断I是否<=600000
			p=100000*0.1+100000*0.075+200000*0.05+(I-400000)*0.03;//若是，则按此公式计算p
		else if(I<=1000000)//若否，则判断I是否<=1000000
			p=100000*0.1+100000*0.075+200000*0.05+200000*0.03+(I-600000)*0.015;//若是，则按此公式计算p
			else p=100000*0.1+100000*0.075+200000*0.05+200000*0.03+4000000*0.015+(I-1000000)*0.01;//若否，则按此公式计算p
	printf("奖金=%f",p);//输出p
	return 0;
}
