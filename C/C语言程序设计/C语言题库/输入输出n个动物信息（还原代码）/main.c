#include<stdio.h>


struct animal
{
/******start******/
 int No;
 char name[999];
 int count;
}ani[50];
int main()
{
    int i,n;
    printf("Input the number(<50):\n");
    scanf("%d",&n);
    for (i = 0; i < n; i++)
    {
        scanf("%d %s %d",&ani[i].No,ani[i].name,&ani[i].count);
    }

/******end******/

	printf("Output:\n");
	for (i = 0; i < n; i++)
	{
		printf("%d ", ani[i].No);
		printf("%s ", ani[i].name);
		printf("%d\n", ani[i].count);
	}

	return 0;
}
