#include "main.h"

void Fileoutdouble(double* a)
{
	cout << "正在导出数据文件...\n";
	ofstream out("整理数据.txt");
	for (int i = 0; i < N; i++)
	{
		out << a[i];
		out << " ";
	}
	out.close();
	cout << "数据文件导出完成！\n";
}