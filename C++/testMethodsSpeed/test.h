#pragma once   
#include <iostream>
using namespace std;
#include <time.h>
#include<assert.h>
#include<stack>
#define M 200 /* ִ�д��� */
#define N 2000000 /* �����С */

void Menu();//�˵�����
void BubbleSort(int* a, size_t n);//1��ð������
void InsertSort(int* a, size_t n);//2,��������
void SheelSort(int* a, size_t n);//3,ϣ������
void SelectSort(int* a, size_t n);//4,ѡ������
void QuickSort(int* a, size_t left, size_t right);//5�����������㷨
void HeapSort(int* a, size_t n);//6��������
void MergeSort(int* a, size_t n);//7,�鲢����
void CountSort(int* a, size_t n);//8,��������
void LSDSort(int* a, size_t n);//9����������