#include <stdio.h>

void fun(double *sn, int n);

int main(void)
{
	int n;
	double Sum;

printf("Please input n: ");
	scanf("%d", &n);

/* �����ִ��빦�ܽ��飺������Ӧ�ĺ�������S */
	/* Limit: lines<=1, lineLen<=50, �������ڱ��к���Ӵ��롢���1�С��г�<=50�ַ� */
	/******start******/
    fun(&Sum, n);
/******end******/
	/* ������Ӵ������ */

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

/* �������ڱ��к���Ӵ��롢���1�С��г�<=30�ַ�) */
	/******start******/
*sn = Sum;
/******end******/
	/* ������Ӵ�������� */
}
