#include "main.h"
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <time.h>
using namespace std;

//大量double型数据随机生成方法(随机生成+文件写入)
void RandomDouble()
{
	cout << "开始创建double型数据文件...\n";
	fstream fso("原始数据.txt", ios::out);
	int i;
	double m = 10.00;
	double n;
	for (i = 0; i < N; ++i) {
		n = rand() / m;
		fso << n << ' ';
	}
	fso.close();
	cout << "double型数据文件创建完成！\n";
}