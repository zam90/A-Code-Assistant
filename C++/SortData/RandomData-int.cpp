#include "main.h"
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <time.h>
using namespace std;

//大量int型数据随机生成方法(随机生成+文件写入)
void RandomInt()
{
	cout << "开始创建int型数据文件...\n";
	fstream fso("原始数据.txt", ios::out);
	int i;
	for (i = 0; i < N; ++i)
		fso << rand() << ' ';
	fso.close();
	cout << "int型数据文件创建完成！\n";
}