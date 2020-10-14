#include "main.h"

void Filein(int* a)
{
	cout << "正在导入数据文件...\n";
	ifstream in("原始数据.txt");
	for (int i = 0; i < N; i++)
		in >> a[i];
	in.close();
	cout << "数据文件导入完成！\n";
}