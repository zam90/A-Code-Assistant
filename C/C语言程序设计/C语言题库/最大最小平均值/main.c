#include <stdio.h>
#include <stdlib.h>


int Compare(int ,int ,int (*Fun)(int ,int ));//�Ƚϴ�С�ĺ���
int GetMax(int ,int );//ȡ���ֵ����
int GetMin(int ,int );//ȡ��Сֵ����
int GetAverage(int ,int );//ȥȡƽ��ֵ����


int main()
{
	int Number1 = 0,Number2 = 0;
	int Result[3],i =0 ;//Result����������洢�����ֵ����Сֵ��ƽ��ֵ
	printf("output:\ninput two numbers:\n");

	scanf("%d%d",&Number1,&Number2);

	if(Number1 == Number2)
	{
		printf("���������ͬ�����֣�\n");
		return 0;
	}

	/*��start��end֮����ɶ�compare�����ĵ��úͲ����Ĵ����Լ�����ֵ�Ĵ洢*/
	/******start******/
    Result[0]=GetMax(Number1,Number2);
	Result[1]=GetMin(Number1,Number2);
    Result[2]=GetAverage(Number1,Number2);

/******end******/

	printf("\n����� ��С�� ƽ��ֵ\n");
	for(i=0;i<3;i++)
	{
		printf("%6d",Result[i]);
	}

	printf("\n");
	return 0;
}

int Compare(int x,int y,int (*Fun)(int ,int ))
{
	//��ɶ�GetMax,Getmin,Getaverage�����ĵ��úͺ����ķ���ֵ
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
