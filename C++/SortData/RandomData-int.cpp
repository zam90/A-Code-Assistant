#include "main.h"
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <time.h>
using namespace std;

//����int������������ɷ���(�������+�ļ�д��)
void RandomInt()
{
	cout << "��ʼ����int�������ļ�...\n";
	fstream fso("ԭʼ����.txt", ios::out);
	int i;
	for (i = 0; i < N; ++i)
		fso << rand() << ' ';
	fso.close();
	cout << "int�������ļ�������ɣ�\n";
}