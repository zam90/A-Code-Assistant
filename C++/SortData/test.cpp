#include "main.h"

int main()
{
	RandomDouble();
	int i, j, p;
	double a[N];
	Fileindouble(a);
	SheelSortdouble(a, N);
	Fileoutdouble(a);
	cout << "���������\n";
	cin.get();//��ͣ���ڣ��ȴ�ָ��
}