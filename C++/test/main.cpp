#include <stdio.h>
#define NUM 10

int  main()
{
	int a[NUM];
	int i, j;
	errno_t err; FILE* fp;
	err = fopen_s( &fp, "data.txt", "r");
	if (fp == NULL)
	{
		printf("无文件");
		return -1;
	}
	for (i = 0; i < NUM; i++)
	{
		fscanf_s(fp, "%d", &a[i]);
	}
	fclose(fp);
	int max = a[0];
	for (i = 0; i < NUM; i++)
	{
		if (a[i] > max) {
			max = a[i];
		}
	}
	int min = a[0];
	for (i = 0; i < NUM; i++)
	{
		if (a[i] < min) {
			min = a[i];
		}
	}
	int all = 0;
	int average = 0;
	for (i = 0; i < NUM; i++)
	{
		all = all + a[i];
	}
	average = all / i;
	int lessNum = 0;
	for (i = 0; i < NUM; i++)
	{
		if(a[i] < average) {
			lessNum++;
		}
	}
	int largeNum = 0;
	for (i = 0; i < NUM; i++)
	{
		if (a[i] > average) {
			largeNum++;
		}
	}
	printf("最大：%d 最小：%d 平均：%d\n小于均值的个数：%d 大于均值的个数：%d\n", max, min, average, lessNum, largeNum);
	return 0;
}