#include "main.h"

void Fileoutdouble(double* a)
{
	cout << "���ڵ��������ļ�...\n";
	ofstream out("��������.txt");
	for (int i = 0; i < N; i++)
	{
		out << a[i];
		out << " ";
	}
	out.close();
	cout << "�����ļ�������ɣ�\n";
}