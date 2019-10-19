#include <stdio.h>
#include <stdlib.h>


int Compare(int ,int ,int (*Fun)(int ,int ));//比较大小的函数
int GetMax(int ,int );//取最大值函数
int GetMin(int ,int );//取最小值函数
int GetAverage(int ,int );//去取平均值函数


int main()
{
	int Number1 = 0,Number2 = 0;
	int Result[3],i =0 ;//Result数组用来存存储的最大值，最小值和平均值
	printf("output:\ninput two numbers:\n");

	scanf("%d%d",&Number1,&Number2);

	if(Number1 == Number2)
	{
		printf("输入二个不同的数字：\n");
		return 0;
	}

	/*在start和end之间完成对compare函数的调用和参数的传递以及返回值的存储*/
	/******start******/
    Result[0]=GetMax(Number1,Number2);
	Result[1]=GetMin(Number1,Number2);
    Result[2]=GetAverage(Number1,Number2);

/******end******/

	printf("\n最大数 最小数 平均值\n");
	for(i=0;i<3;i++)
	{
		printf("%6d",Result[i]);
	}

	printf("\n");
	return 0;
}

int Compare(int x,int y,int (*Fun)(int ,int ))
{
	//完成对GetMax,Getmin,Getaverage函数的调用和函数的返回值
	/******start******/
return 0;
/******end******/
}

int GetMax(int x,int y)
{
	return (x>y)? x:y;
}

int GetMin(int x,int y)
{
	return (x>y)? y:x;
}

int GetAverage(int x,int y)
{
	return (x+y)/2;
}
