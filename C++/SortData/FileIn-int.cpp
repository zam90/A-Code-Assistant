#include "main.h"

void Filein(int* a)
{
	cout << "���ڵ��������ļ�...\n";
	ifstream in("ԭʼ����.txt");
	for (int i = 0; i < N; i++)
		in >> a[i];
	in.close();
	cout << "�����ļ�������ɣ�\n";
}