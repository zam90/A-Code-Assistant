#include "main.h"

//希尔排序函数核心(int型)
void SheelSort(int* a, size_t n)
{
	cout << "开始排序...\n";
	assert(a);
	int gub = n / 2;//先定义增量为n/2
	while (gub > 0)
	{
		for (size_t i = gub; i < n; ++i)//从第gub个数据处开始进行交换
		{
			int tmp = a[i];
			int end = i - gub;
			while (end >= 0 && tmp < a[end])
			{
				a[end + gub] = a[end];
				end = end - gub;
			}
			a[end + gub] = tmp;
		}
		gub /= 2;
	}
	cout << "排序完成！\n";
}