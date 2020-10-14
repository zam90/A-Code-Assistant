#pragma once   
#include <iostream>
using namespace std;
#include <time.h>
#include<assert.h>
#include<stack>
#define M 200 /* 执行次数 */
#define N 2000000 /* 数组大小 */

void Menu();//菜单函数
void BubbleSort(int* a, size_t n);//1，冒泡排序
void InsertSort(int* a, size_t n);//2,插入排序
void SheelSort(int* a, size_t n);//3,希尔排序
void SelectSort(int* a, size_t n);//4,选择排序
void QuickSort(int* a, size_t left, size_t right);//5，快速排序算法
void HeapSort(int* a, size_t n);//6，堆排序
void MergeSort(int* a, size_t n);//7,归并排序
void CountSort(int* a, size_t n);//8,计数排序
void LSDSort(int* a, size_t n);//9，基数排序