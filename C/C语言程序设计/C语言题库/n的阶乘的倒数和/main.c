#include <stdio.h>

void fun(double *sn, int n);

int main(void)
{
	int n;
	double Sum;

printf("Please input n: ");
	scanf("%d", &n);

/* 本部分代码功能建议：调用相应的函数计算S */
	/* Limit: lines<=1, lineLen<=50, 考生可在本行后添加代码、最多1行、行长<=50字符 */
	/******start******/
    fun(&Sum, n);
/******end******/
	/* 考生添加代码结束 */

printf("Output:\nS=1/1!+1/2!+...+1/%d!=%.16f", n, Sum);
	return 0;
}


void fun(double *sn, int n)
{
	int i;
	double Sum=0, jc=1;

for (i=1; i<=n; i++)
	{
		jc *= i;
		Sum += 1 / jc;
	}

/* 考生可在本行后添加代码、最多1行、行长<=30字符) */
	/******start******/
*sn = Sum;
/******end******/
	/* 考生添加代码结束。 */
}
