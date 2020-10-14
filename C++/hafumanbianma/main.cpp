#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define M 100
typedef struct Fano_Node
{
	char ch;
	float weight;
}FanoNode[M];
typedef struct node
{
	int start;
	int end;
	struct node* next;
}LinkQueueNode;
typedef struct
{
	LinkQueueNode* front;
	LinkQueueNode* rear;
}LinkQueue;
//��������
void EnterQueue(LinkQueue* q, int s, int e)
{
	LinkQueueNode* NewNode;
	//�����½ڵ�
	NewNode = (LinkQueueNode*)malloc(sizeof(LinkQueueNode));
	if (NewNode != NULL)
	{
		NewNode->start = s;
		NewNode->end = e;
		NewNode->next = NULL;
		q->rear->next = NewNode;
		q->rear = NewNode;
	}
	else
	{
		printf("Error!");
		exit(-1);
	}
}
//��Ȩ����
void Divide(FanoNode f, int s, int* m, int e)
{
	int i;
	float sum, sum1;
	sum = 0;
	for (i = s; i <= e; i++)
		sum += f[i].weight;//
	*m = s;
	sum1 = 0;
	for (i = s; i < e; i++)
	{
		sum1 += f[i].weight;
		*m = fabs(sum - 2 * sum1) > fabs(sum - 2 * sum1 - 2 * f[i + 1].weight) ? (i + 1) : *m;
		if (*m == i) break;
	}
}
void main()
{
	int i, j, n, max, m, h[M];
	int sta, end;
	float w;
	char c, fc[M][M];
	FanoNode FN;
	LinkQueueNode* p;
	LinkQueue* Q;
	//��ʼ����Q
	Q = (LinkQueue*)malloc(sizeof(LinkQueue));
	Q->front = (LinkQueueNode*)malloc(sizeof(LinkQueueNode));
	Q->rear = Q->front;
	Q->front->next = NULL;
	printf("\t***FanoCoding***\n");
	printf("Please input the number of node:");
	//������Ϣ
	scanf_s("%d", &n);
	//��������M,�˳�
	if (n >= M)
	{
		printf(">=%d", M);
		exit(-1);
	}
	i = 1; //�ӵڶ���Ԫ�ؿ�ʼ¼��
	while (i <= n)
	{
		printf("%d weight and node:", i);
		scanf_s("%f %c", &FN[i].weight, &FN[i].ch);
		for (j = 1; j < i; j++)
		{
			if (FN[i].ch == FN[j].ch)//�����ظ�
			{
				printf("Same node!!!\n"); break;
			}
		}
		if (i == j)
			i++;
	}
	//����(����)
	for (i = 1; i <= n; i++)
	{
		max = i + 1;
		for (j = max; j <= n; j++)
			max = FN[max].weight < FN[j].weight ? j : max;
		if (FN[i].weight < FN[max].weight)
		{
			w = FN[i].weight;
			FN[i].weight = FN[max].weight;
			FN[max].weight = w;
			c = FN[i].ch;
			FN[i].ch = FN[max].ch;
			FN[max].ch = c;
		}
	}
	for (i = 1; i <= n; i++) //��ʼ��h
		h[i] = 0;
	EnterQueue(Q, 1, n); //1��n����
	while (Q->front->next != NULL)
	{
		p = Q->front->next; //����
		Q->front->next = p->next;
		if (p == Q->rear)
			Q->rear = Q->front;
		sta = p->start;
		end = p->end;
		free(p);
		Divide(FN, sta, &m, end); /*��Ȩ����*/
		for (i = sta; i <= m; i++)
		{
			fc[i][h[i]] = '0';
			++h[i];
		}
		if (sta != m)
			EnterQueue(Q, sta, m);
		else
			fc[sta][h[sta]] = '\0';
		for (i = m + 1; i <= end; i++)
		{
			fc[i][h[i]] = '1';
			++h[i];
		}
		if (m == sta && (m + 1) == end)
			//����������Ԫ�ص��±����м�Ԫ�ص���ȣ�
			//���Һ����Ԫ�ص��±����Ϊ1������������ַ�������
		{
			fc[m][h[m]] = '\0';
			fc[end][h[end]] = '\0';
		}
		else
			EnterQueue(Q, m + 1, end);
	}
	for (i = 1; i <= n; i++) /*��ӡ������Ϣ*/
	{
		printf("%c:", FN[i].ch);
		printf("%s\n", fc[i]);
	}
	system("pause");
}