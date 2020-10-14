#include"test.h"
void main()
{
	int a[N], i, j, p;
	Menu();
	do {
		cin >> p;
		double start, finish; /* 定义开始的时间和结束的时间 */
		start = (double)clock();
		for (j = 0; j < M; j++)
		{ /* 执行M次 */
			for (i = 0; i < N; *(a + i++) = rand() % 10); /* 每次对数组进行重新赋值 */
			switch (p)
			{
			case 1:BubbleSort(a, N);
				break;
			case 2:InsertSort(a, N);
				break;
			case 3:SheelSort(a, N);
				break;
			case 4:SelectSort(a, N);
				break;
			case 5:QuickSort(a, 0, N - 1);
				break;
			case 6:HeapSort(a, N);
				break;
			case 7:MergeSort(a, N);
				break;
			case 8:CountSort(a, N);
				break;
			case 9:LSDSort(a, N);
			case 0:break;
			default:break;
			}
		}
		finish = (double)clock();
		printf("%.4fms\n", (finish - start));
	} while (p != 0);
}