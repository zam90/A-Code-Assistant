#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cstring>
using namespace std;
#define N 100
#define M 2*N-1
typedef char* HuffmanCode[2 * M];//haffman����
typedef struct
{
	int weight;//Ȩֵ
	int parent;//���ڽڵ�
	int LChild;//���ӽڵ�
	int RChild;//���ӽڵ�
}HTNode, Huffman[M + 1];//huffman��
typedef struct Node
{
	int weight; //Ҷ�ӽ���Ȩֵ
	char c; //Ҷ�ӽ��
	int num; //Ҷ�ӽ��Ķ�������ĳ���
}WNode, WeightNode[N];
/***����Ҷ�ӽ����ַ���Ȩֵ***/
void CreateWeight(char ch[], int* s, WeightNode CW, int* p)
{
	int i, j, k;
	int tag;
	*p = 0;//Ҷ�ӽڵ����
	//ͳ���ַ����ָ���,����CW
	for (i = 0; ch[i] != '\0'; i++)
	{
		tag = 1;
		for (j = 0; j < i; j++)
			if (ch[j] == ch[i])
			{
				tag = 0;
				break;
			}
		if (tag)
		{
			CW[++ * p].c = ch[i];
			CW[*p].weight = 1;
			for (k = i + 1; ch[k] != '\0'; k++)
				if (ch[i] == ch[k])
					CW[*p].weight++;//Ȩֵ�ۼ�
		}
	}
	*s = i;//�ַ�������
}
/********����HuffmanTree********/
void CreateHuffmanTree(Huffman ht, WeightNode w, int n)
{
	int i, j;
	int s1, s2;
	//��ʼ����������
	for (i = 1; i <= n; i++)
	{
		ht[i].weight = w[i].weight;
		ht[i].parent = 0;
		ht[i].LChild = 0;
		ht[i].RChild = 0;
	}
	for (i = n + 1; i <= 2 * n - 1; i++)
	{
		ht[i].weight = 0;
		ht[i].parent = 0;
		ht[i].LChild = 0;
		ht[i].RChild = 0;
	}
	for (i = n + 1; i <= 2 * n - 1; i++)
	{
		for (j = 1; j <= i - 1; j++)
			if (!ht[j].parent)
				break;
		s1 = j; //�ҵ���һ��˫��Ϊ��Ľ��
		for (; j <= i - 1; j++)
			if (!ht[j].parent)
				s1 = ht[s1].weight > ht[j].weight ? j : s1;
		ht[s1].parent = i;
		ht[i].LChild = s1;
		for (j = 1; j <= i - 1; j++)
			if (!ht[j].parent)
				break;
		s2 = j; //�ҵ��ڶ���˫��Ϊ��Ľ��
		for (; j <= i - 1; j++)
			if (!ht[j].parent)
				s2 = ht[s2].weight > ht[j].weight ? j : s2;
		ht[s2].parent = i;
		ht[i].RChild = s2;
		ht[i].weight = ht[s1].weight + ht[s2].weight;//Ȩֵ�ۼ�
	}
}
/***********Ҷ�ӽ��ı���***********/
void CrtHuffmanNodeCode(Huffman ht, char ch[], HuffmanCode h, WeightNode weight, int m, int n)
{
	int i, c, p, start;
	char* cd;
	cd = (char*)malloc(n * sizeof(char));
	cd[n - 1] = '\0';//ĩβ��0
	for (i = 1; i <= n; i++)
	{
		start = n - 1; //cd��ÿ�δ�ĩβ��ʼ
		c = i;
		p = ht[i].parent;//p��n+1��2n-1
		while (p) //�ظ��׷������,ֱ��Ϊ0
		{
			start--;//������ǰ��ֵ
			if (ht[p].LChild == c)//��������ͬ,��0
				cd[start] = '0';
			else //������1
				cd[start] = '1';
			c = p;
			p = ht[p].parent;
		}
		weight[i].num = n - start; //��������ĳ���(����ĩβ0)
		h[i] = (char*)malloc((n - start) * sizeof(char));
		strcpy_s(h[i], strlen(cd) + 1,&cd[start]);//���������ַ���������ָ������h��
	}
	free(cd);//�ͷ�cd�ڴ�
	system("pause");
}
/*********�����ַ��ı���*********/
void CrtHuffmanCode(char ch[], HuffmanCode h, HuffmanCode hc, WeightNode weight, int n, int m)
{
	int i, k;
	for (i = 0; i < m; i++)
	{
		for (k = 1; k <= n; k++) /*��weight[k].c�в�����ch[i]��ȵ��±�K*/
			if (ch[i] == weight[k].c)
				break;
		hc[i] = (char*)malloc((weight[k].num) * sizeof(char));
		strcpy_s(hc[i], strlen(h[k]) + 1, h[k]); //���������Ʊ���
	}
}
/*****����*****/
void TrsHuffmanTree(Huffman ht, WeightNode w, HuffmanCode hc, int n, int m)
{
	int i = 0, j, p;
	printf("***StringInformation***\n");
	while (i < m)
	{
		p = 2 * n - 1;//�Ӹ��׽ڵ����±���ֱ��Ҷ�ӽڵ�
		for (j = 0; hc[i][j] != '\0'; j++)
		{
			if (hc[i][j] == '0')
				p = ht[p].LChild;
			else
				p = ht[p].RChild;
		}
		printf("%c", w[p].c); /*��ӡԭ��Ϣ*/
		i++;
	}
}
/*****�ͷ�huffman�����ڴ�*****/
void FreeHuffmanCode(HuffmanCode h, HuffmanCode hc, int n, int m)
{
	int i;
	for (i = 1; i <= n; i++)//�ͷ�Ҷ�ӽ��ı���
		free(h[i]);
	for (i = 0; i < m; i++) //�ͷ����н��ı���
		free(hc[i]);
}
void main()
{
	int i, n = 0; /*nΪҶ�ӽ��ĸ���*/
	int m = 0; /*mΪ�ַ���ch[]�ĳ���*/
	char ch[N]; /*ch[N]���������ַ���*/
	Huffman ht; /*Huffman������*/
	HuffmanCode h, hc; /*h���Ҷ�ӽ��ı��룬hc ������н��ı���*/
	WeightNode weight; /*���Ҷ�ӽ�����Ϣ*/
	printf("\t***HuffmanCoding***\n");
	printf("please input information :");
	gets_s(ch); /*�����ַ���*/
	CreateWeight(ch, &m, weight, &n); /*����Ҷ�ӽ����Ϣ��mΪ�ַ���ch[]�ĳ���*/
	printf("***WeightInformation***\n Node ");
	for (i = 1; i <= n; i++) /*���Ҷ�ӽ����ַ���Ȩֵ*/
		printf("%c ", weight[i].c);
	printf("\nWeight ");
	for (i = 1; i <= n; i++)
		printf("%d ", weight[i].weight);
	CreateHuffmanTree(ht, weight, n); /*����Huffman��*/
	printf("\n***HuffamnTreeInformation***\n");
	printf("\ti\tweight\tparent\tLChild\tRChild\n");
	for (i = 1; i <= 2 * n - 1; i++) /*��ӡHuffman������Ϣ*/
		printf("\t%d\t%d\t%d\t%d\t%d\n", i, ht[i].weight, ht[i].parent, ht[i].LChild, ht[i].RChild);
	CrtHuffmanNodeCode(ht, ch, h, weight, m, n); /*Ҷ�ӽ��ı���*/
	printf(" ***NodeCode***\n"); /*��ӡҶ�ӽ��ı���*/
	for (i = 1; i <= n; i++)
	{
		printf("\t%c:", weight[i].c);
		printf("%s\n", h[i]);
	}
	CrtHuffmanCode(ch, h, hc, weight, n, m); /*�����ַ��ı���*/
	printf("***StringCode***\n"); /*��ӡ�ַ����ı���*/
	for (i = 0; i < m; i++)
		printf("%s", hc[i]);
	system("pause");
	TrsHuffmanTree(ht, weight, hc, n, m); /*����*/
	FreeHuffmanCode(h, hc, n, m);
	system("pause");
}