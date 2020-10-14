
#include <iostream>
#include <string.h>
using namespace std;
#define MAXWEIGHT 100	//���Ȩֵ

//���������ڵ�
typedef struct HTNode{
	char words, * code;
	int weight;
	int parent, lchild, rchild;
}* HuffmanTree;

int n;
char coding[100];

//Ѱ��Ȩֵ��С�ڵ�
int Findmin(HuffmanTree& HT, int i)
{
	int j;
	unsigned int k = MAXWEIGHT;	//����Ȩֵ������MAXWEIGHT
	int flag = 0;
	for (j = 0; j <= i; ++j)
	{
		if (HT[j].weight < k && HT[j].parent == 0)//�жϴ˽ڵ��Ƿ��Ѿ�ѡ�񣬸����Ϊ0��δ��ѡ�񣬸����Ϊ1��ѡ��
		{
			k = HT[j].weight;
			flag = j;
		}
	}
	HT[flag].parent = 1;
	return flag;
}

//ѡ��Ȩֵ��С�������ڵ�
void Select(HuffmanTree& HT, int i, int& s1, int& s2)
{
	s1 = Findmin(HT, i);
	s2 = Findmin(HT, i);
}

//������������
void CreateHuffmanTree(HuffmanTree& HT, char t[], int w[])
{
	int m;
	int i, s1, s2;
	if (n <= 1)	//���ֻ��һ���ڵ�Ͳ���Ҫ������������
		return;
	m = 2 * n - 1; //��Ҫ2n��1���ڵ�
	HT = new HTNode[m + 1];
	for (i = 0; i < n; i++)
	{
		HT[i].parent = 0;
		HT[i].lchild = 0;
		HT[i].rchild = 0;
		HT[i].words = t[i];
		HT[i].weight = w[i];

	}
	for (i = n; i <= m; i++)
	{
		HT[i].parent = 0;
		HT[i].lchild = 0;
		HT[i].rchild = 0;
		HT[i].words = ' ';
		HT[i].weight = 0;
	}
	for (i = n; i < m; i++)
	{
		Select(HT, i - 1, s1, s2);//��n�������ҳ�Ȩֵ��С������
		HT[s1].parent = i;
		HT[s2].parent = i;//������������parent�ڵ�����Ϊi;

		HT[i].lchild = s1;
		HT[i].rchild = s2;//���������ֱ������ҽڵ�
		HT[i].weight = HT[s1].weight + HT[s2].weight;//����������˫��Ϊ���������ĺͣ�

	}
}

//���й���������
void Encode(HuffmanTree HT)
{
	int begin, c, f;
	int i;
	char* code = new char[n];
	code[n - 1] = '\0';
	cout << "\n�ַ������ַ��Ĺ���������Ϊ��" << endl;
	for (i = 0; i < n; i++)
	{
		begin = n - 1;
		c = i;
		f = HT[i].parent;
		while (f != 0) {
			--begin;
			if (HT[f].lchild == c) {

				code[begin] = '0';
			}
			else {

				code[begin] = '1';
			}
			c = f;
			f = HT[f].parent;
		}

		HT[i].code = new char[n - begin];
		strcpy_s(HT[i].code, strlen(code) + 1,&code[begin]);
		cout << HT[i].words << ":" << HT[i].code << endl;
	}
	delete code;
}

//�ɹ���������������
void Decode(HuffmanTree HT, char code[], int b)
{
	char sen[100];
	char temp[50];
	char voidstr[] = " ";
	int t = 0;
	int s = 0;
	int xx = 0;
	for (int i = 0; i < b; i++)
	{
		temp[t++] = code[i];//��ȡ�ַ�
		temp[t] = '\0';
		for (int j = 0; j < n; j++) {//�����������ַ����뿪ʼƥ��

			if (!strcmp(HT[j].code, temp)) {

				sen[s] = HT[j].words;
				s++;
				xx += t;
				strcpy_s(temp, strlen(voidstr) + 1,voidstr);//�ÿ�Temp
				t = 0;
				break;
			}
		}
	}
	//t���ÿ�˵��ƥ��ɹ�
	if (t == 0) {
		sen[s] = '\0';
		cout << "������Ϊ:" << endl;
		cout << sen << endl;
	}
	//t���û�б��ÿ� �� Դ���޷�����ȫƥ��
	else {
		cout << "������������ʧ�ܣ��ӵ�" << xx + 1 << "λ��ʼ" << endl;
	}
}

//�ж������ַ��Ƿ�Ϸ�������
void JudgeDecode(HuffmanTree HT)
{
	char deCodeStr;	//��������ʱ���ַ�
	int symbol = 1, x, k; //����ʱ���ж��õı���  
	cout << "\n��������������" << endl;
	while (1)
	{
		cout << "��������Ҫ�����01�ַ���,��'#'������";
		x = 1;//�ж��Ƿ��зǷ��ַ�
		k = 0;
		symbol = 1;//��������ı�־
		while (symbol) {
			cin >> deCodeStr;
			if (deCodeStr != '1' && deCodeStr != '0' && deCodeStr != '#') { //�����������ַ���x��Ϊ0����ʾ����Ƿ�
				x = 0;
			}
			coding[k] = deCodeStr;
			if (deCodeStr == '#')
				symbol = 0;  //#�Ž�����־
			k++;
		}
		//����Ϸ� ��������
		if (x == 1) {
			Decode(HT, coding, k - 1);//��������
		}
		else {
			cout << "�������������ַ���������0��1" << endl;
		}
		break;
	}
}

//������
int main()
{
	HuffmanTree HT;
	char a[100];	//����ַ�
	char enCodeStr[1024];	//������ַ���
	int w[100];	//���Ȩֵ��Ϣ
	int  i, j;
	cout << "����������\n�������ַ�����";
	cin.getline(enCodeStr, 1024);	//��������ַ��������������enCodeStr
	int len = strlen(enCodeStr);	//����lenΪenCodeStr�ַ����ĳ���
	//����ַ�����Ȩֵ��Ϣ
	for (i = 0; i < len; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (a[j] == enCodeStr[i])
			{
				w[j] = w[j] + 1;
				break;
			}
		}
		if (j >= n)
		{
			a[n] = enCodeStr[i];
			w[n] = 1;
			n++;
		}
	}
	//��ӡ�ַ�Ȩֵ��Ϣ
	cout << "\n�ַ���Ȩֵ��Ϣ������ʾ\n�ַ�    Ȩֵ" << endl;
	for (i = 0; i < n; i++)
	{
		cout << " " << a[i] << "        " << w[i] << endl;
	}
	//�����������������й���������
	CreateHuffmanTree(HT, a, w);
	Encode(HT);
	//�ж������ַ��Ƿ�Ϸ�������
	JudgeDecode(HT);
	return 0;
}