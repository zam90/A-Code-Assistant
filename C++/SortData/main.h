#pragma once
#include <fstream>
#include <iostream>
#include<assert.h>
using namespace std;

#define N 1200000 //��������С(�����С)

//����int������������ɷ���(�������+�ļ�д��)
void RandomInt();

//����double������������ɷ���(�������+�ļ�д��)
void RandomDouble();

//int�����ݵ��뷽��(�ļ���ȡ+���鸳ֵ)
void Filein(int* a);

//double�����ݵ��뷽��(�ļ���ȡ+���鸳ֵ)
void Fileindouble(double* a);

//int�����ݵ�������(�����ȡ+�ļ�д��)
void Fileout(int* a);

//double�����ݵ�������(�����ȡ+�ļ�д��)
void Fileoutdouble(double* a);

//ϣ������������(int��)
void SheelSort(int* a, size_t n);

//ϣ������������(double��)
void SheelSortdouble(double* a, size_t n);