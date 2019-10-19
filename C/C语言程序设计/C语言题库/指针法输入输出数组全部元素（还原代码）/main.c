#include <stdio.h>
#include <stdlib.h>

int main()
{
	int *a;
	int i;


	printf("please enter 5 integer numbers:");

        a = (int *)malloc(5*sizeof(int));

	for(i=0;i<5;i++)
	{
		/******start******/
    scanf("%d",(a+i));
/******end******/
	}
	printf("Output:\n");
	for(i=0;i<5;i++)
	{
		/******start******/
    printf("%d ",*(a+i));
/******end******/
	}
	printf("\n");
	return 0;
}
