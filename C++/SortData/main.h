#pragma once
#include <fstream>
#include <iostream>
#include<assert.h>
using namespace std;

#define N 1200000 //数据量大小(数组大小)

//大量int型数据随机生成方法(随机生成+文件写入)
void RandomInt();

//大量double型数据随机生成方法(随机生成+文件写入)
void RandomDouble();

//int型数据导入方法(文件读取+数组赋值)
void Filein(int* a);

//double型数据导入方法(文件读取+数组赋值)
void Fileindouble(double* a);

//int型数据导出方法(数组读取+文件写入)
void Fileout(int* a);

//double型数据导出方法(数组读取+文件写入)
void Fileoutdouble(double* a);

//希尔排序函数核心(int型)
void SheelSort(int* a, size_t n);

//希尔排序函数核心(double型)
void SheelSortdouble(double* a, size_t n);