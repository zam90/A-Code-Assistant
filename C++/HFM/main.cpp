
#include <iostream>
#include <string.h>
using namespace std;
#define MAXWEIGHT 100	//最大权值

//哈弗曼树节点
typedef struct HTNode{
	char words, * code;
	int weight;
	int parent, lchild, rchild;
}* HuffmanTree;

int n;
char coding[100];

//寻找权值最小节点
int Findmin(HuffmanTree& HT, int i)
{
	int j;
	unsigned int k = MAXWEIGHT;	//假设权值不超过MAXWEIGHT
	int flag = 0;
	for (j = 0; j <= i; ++j)
	{
		if (HT[j].weight < k && HT[j].parent == 0)//判断此节点是否已经选择，父结点为0则未被选择，父结点为1则被选择
		{
			k = HT[j].weight;
			flag = j;
		}
	}
	HT[flag].parent = 1;
	return flag;
}

//选择权值最小的两个节点
void Select(HuffmanTree& HT, int i, int& s1, int& s2)
{
	s1 = Findmin(HT, i);
	s2 = Findmin(HT, i);
}

//创建哈夫曼树
void CreateHuffmanTree(HuffmanTree& HT, char t[], int w[])
{
	int m;
	int i, s1, s2;
	if (n <= 1)	//如果只有一个节点就不需要创建哈夫曼树
		return;
	m = 2 * n - 1; //需要2n－1个节点
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
		Select(HT, i - 1, s1, s2);//在n个数中找出权值最小的两个
		HT[s1].parent = i;
		HT[s2].parent = i;//将他们两个的parent节点设置为i;

		HT[i].lchild = s1;
		HT[i].rchild = s2;//把这两个分别当作左右节点
		HT[i].weight = HT[s1].weight + HT[s2].weight;//他们两个的双亲为他们两个的和；

	}
}

//进行哈夫曼编码
void Encode(HuffmanTree HT)
{
	int begin, c, f;
	int i;
	char* code = new char[n];
	code[n - 1] = '\0';
	cout << "\n字符串各字符的哈夫曼编码为：" << endl;
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

//由哈夫曼树进行译码
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
		temp[t++] = code[i];//读取字符
		temp[t] = '\0';
		for (int j = 0; j < n; j++) {//依次与所有字符编码开始匹配

			if (!strcmp(HT[j].code, temp)) {

				sen[s] = HT[j].words;
				s++;
				xx += t;
				strcpy_s(temp, strlen(voidstr) + 1,voidstr);//置空Temp
				t = 0;
				break;
			}
		}
	}
	//t被置空说明匹配成功
	if (t == 0) {
		sen[s] = '\0';
		cout << "译码结果为:" << endl;
		cout << sen << endl;
	}
	//t如果没有被置空 ， 源码无法被完全匹配
	else {
		cout << "输入有误，译码失败！从第" << xx + 1 << "位开始" << endl;
	}
}

//判断译码字符是否合法并译码
void JudgeDecode(HuffmanTree HT)
{
	char deCodeStr;	//输入译码时的字符
	int symbol = 1, x, k; //译码时做判断用的变量  
	cout << "\n哈夫曼编码译码" << endl;
	while (1)
	{
		cout << "请输入需要译码的01字符串,以'#'结束：";
		x = 1;//判断是否有非法字符
		k = 0;
		symbol = 1;//输入结束的标志
		while (symbol) {
			cin >> deCodeStr;
			if (deCodeStr != '1' && deCodeStr != '0' && deCodeStr != '#') { //若存在其它字符，x设为0，表示输入非法
				x = 0;
			}
			coding[k] = deCodeStr;
			if (deCodeStr == '#')
				symbol = 0;  //#号结束标志
			k++;
		}
		//输入合法 进行译码
		if (x == 1) {
			Decode(HT, coding, k - 1);//进行译码
		}
		else {
			cout << "输入有误，译码字符仅能输入0和1" << endl;
		}
		break;
	}
}

//主函数
int main()
{
	HuffmanTree HT;
	char a[100];	//存放字符
	char enCodeStr[1024];	//输入的字符串
	int w[100];	//存放权值信息
	int  i, j;
	cout << "哈夫曼编码\n请输入字符串：";
	cin.getline(enCodeStr, 1024);	//获得输入字符串并赋予给变量enCodeStr
	int len = strlen(enCodeStr);	//变量len为enCodeStr字符串的长度
	//获得字符及其权值信息
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
	//打印字符权值信息
	cout << "\n字符和权值信息如下所示\n字符    权值" << endl;
	for (i = 0; i < n; i++)
	{
		cout << " " << a[i] << "        " << w[i] << endl;
	}
	//创建哈夫曼树并进行哈夫曼编码
	CreateHuffmanTree(HT, a, w);
	Encode(HT);
	//判断译码字符是否合法并译码
	JudgeDecode(HT);
	return 0;
}