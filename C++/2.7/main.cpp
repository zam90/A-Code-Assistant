#include<stdio.h>

int find(int n, int m)
{
	if (m == 1 || n == m)
		return 1;
	else
		return find(n - 1, m - 1) + find(n - 1, m) * m;
}

int main()
{
	int n;
	printf("请输入元素个数：");
	scanf_s("%d", &n);
	int i;
	int sum = 0;
	for (i = 1; i <= n; i++)
	{
		sum = sum + find(n, i);
	}
	printf("总集合数：%d\n", sum);
	return 0;
}