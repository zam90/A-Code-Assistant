#include <stdio.h>
#define N 13

struct person
{
	int number;
	int next;
}link[N];

int main()
{
	int i,count,h;
	for(i=1;i<=N;i++)
	{
		if(i==N)
			link[i].next=1;
		else
			link[i].next=i+1;
			link[i].number=i;
	}
	count=0;
	h=N;
	while(count<N-1)
	{
		i=0;
		while(i!=3)
		{
			h=link[h].next;
			if(link[h].number!=0)
			{
				i++;
			}
		}
		if(i==3)
		{
			link[h].number=0;
			count++;
		}
	}
	printf("\n");
	for(i=1;i<=N;i++)
	{
		while(link[i].number==0)
		{
			i++;
		}
		printf("the last numbers:%d\n",link[i].number);
	}
		return 0;
}
