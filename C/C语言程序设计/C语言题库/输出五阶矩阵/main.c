#include <stdio.h>

int main(void)
{
	int n, i, j;
	int array[5][5];

	printf("Please input an integer:");
	scanf("%d", &n);

	printf("Output:\n");
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
		{
			array[i][j] = n + i + j;
			printf("%4d", array[i][j]);
		}
		printf("\n");
	}

	return 0;
}
