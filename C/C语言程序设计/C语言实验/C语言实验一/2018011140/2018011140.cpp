// 2018011140.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include<math.h>


int main(int argc, char* argv[])
{
	double n,r,p;
	r=0.07;//��r��ֵ
	n=10;//��n��ֵ
	double m=pow(1+r,n);//���ú�����������
	p=m*100;//С���ٷ�������
	printf("�����ҹ�����������ֵ����������Ϊ7%%������10����ҹ�����������ֵ����������������ٰٷֱȡ�\n");//��ʾ���
	printf("���Ϊ%f%%\n",p);//��ʾ���
	return 0;
}
