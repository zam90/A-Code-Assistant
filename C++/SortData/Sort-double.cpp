#include "main.h"

//ϣ������������(double��)
void SheelSortdouble(double* a, size_t n)
{
	cout << "��ʼ����...\n";
	assert(a);
	int gub = n / 2;//�ȶ�������Ϊn/2
	while (gub > 0)
	{
		for (size_t i = gub; i < n; ++i)//�ӵ�gub�����ݴ���ʼ���н���
		{
			double tmp = a[i];
			int end = i - gub;
			while (end >= 0 && tmp < a[end])
			{
				a[end + gub] = a[end];
				end = end - gub;
			}
			a[end + gub] = tmp;
		}
		gub /= 2;
	}
	cout << "������ɣ�\n";
}