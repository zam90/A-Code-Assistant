#include "main.h"
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <time.h>
using namespace std;

//����double������������ɷ���(�������+�ļ�д��)
void RandomDouble()
{
	cout << "��ʼ����double�������ļ�...\n";
	fstream fso("ԭʼ����.txt", ios::out);
	int i;
	double m = 10.00;
	double n;
	for (i = 0; i < N; ++i) {
		n = rand() / m;
		fso << n << ' ';
	}
	fso.close();
	cout << "double�������ļ�������ɣ�\n";
}