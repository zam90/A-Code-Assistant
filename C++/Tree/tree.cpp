// Honer Code
// ����ϵر�֤��
// ���Լ��������������������ӷ�������Ƶ���������й�����
// ��������������У���������ʲô���Ѷ�������ˣ���ô���ҽ��ڳ���ʵϰ������
// ��ϸ���о��������������⣬�Լ����˸��ҵ���ʾ��
// �ҵĳ������з������õ�����������ĵ�֮����
// ����̲ġ����ñʼǡ����ϵ�Դ�����Լ������ο����ϵĴ����,
// �Ҷ��Ѿ��ڳ����ע����������ע�������õĳ�����
// �Ҵ�δû��Ϯ�����˵ĳ���Ҳû�е��ñ��˵ĳ���
// �������޸�ʽ�ĳ�Ϯ����ԭ�ⲻ���ĳ�Ϯ��
// �ұ�д������򣬴���û�����Ҫȥ�ƻ���������������ϵͳ��������ת��
// ǩ���ˣ�����1801 �ž��� 2018011140

// �����ĵ�
// �ļ����ƣ�tree.cpp
// ��Ŀ���ƣ�Tree
// �����ߣ��ž���
// ����ʱ�䣺2019.11.4
// ����޸�ʱ�䣺2019.11.5
// ���ܣ����������������������

#include <iostream>	//����IO���ļ�
#include <string.h>
#include <assert.h>
#include <stack>
#define N 15	//NΪ�ڵ���
using namespace std;	//ʹ�ñ�׼�����ռ�

//����ڵ���
class node
{
public:
	int data;	//�ڵ���Ϣ
	node* leftChild;//�ڵ�ָ�룺����
	node* rightChild;//�ڵ�ָ�룺�Һ���
};
typedef node* BiTree;//�ȼۣ�����node*��������BiTree

//�����ڵ㣬��*�ŵ����壺��������ָ��������
node* createNode(int value)
{
	node* q = new node;
	q->leftChild = NULL;	//leftChildָ��Ϊ��
	q->rightChild = NULL;	//rightChildָ��Ϊ��
	q->data = value;	//�ڵ�ֵ����value
	return q;	//���ؽڵ�
}

//����������
BiTree createBiTree()
{
	node* p[N] = { NULL };
	//int array[28] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27 };//Ĭ�Ͻ���28�ڵ������
	//������������ڵ�ֵ���ɶ�����
	cout<<"�밴��������˳��������������ڵ�:"<<endl;	//��ʾ��
	int array[N];	//����array�������ڴ洢�ڵ���Ϣ
	for (int i = 0; i < N; ++i){
		cin >> array[i];	//��������ڵ��ֵ
	}
	for (int i = 0; i < N; ++i)
		p[i] = createNode(array[i]);	//�����ڵ�
	for (int i = 0; i < N / 2; i++)
	{
		p[i]->leftChild = p[i * 2 + 1];	//����ÿ���ڵ�����ָ��
		p[i]->rightChild = p[i * 2 + 2];	//����ÿ���ڵ��Һ���ָ��
	}
	return p[0];
}

//���ʽڵ��е�����
int visit(BiTree tree)
{
	return tree->data;	//���ؽڵ��ֵ
}

//�ݹ齻���������е���������
void exchange(BiTree tree)
{
	BiTree temp;	//�����м������
	if (tree) {
		temp = tree->leftChild;	//�м�������������轻��������������
		tree->leftChild = tree->rightChild;	//�����轻���������Һ��ӵ�ֵ��������
		tree->rightChild = temp;	//���м�����������ֵ�������轻���������Һ���
		//������a,b����������ֵ��ȡ�м����c
		exchange(tree->leftChild);	//�ݹ齻�����ӵ�ֵ
		exchange(tree->rightChild);	//û������ʱ���ݹ齻���Һ��ӵ�ֵ
	}
}

// �ݹ�ǰ�����
void preorderBiTree(BiTree tree)
{
	if (tree)
	{
		cout << visit(tree) << " ";	//��ӡ��ǰ�ڵ�ֵ
		preorderBiTree(tree->leftChild);	//��������
		preorderBiTree(tree->rightChild);	//û������ʱ�������Һ���
	}
}

// �ǵݹ�ǰ�����
void preorderBiTreeNonRecursive(BiTree tree) {
	if (tree == NULL)
		return;
	BiTree node = tree;	//�����ڵ�
	stack<BiTree> nodes;	//�����ڵ�ջ
	while (node || !nodes.empty()) {	//���ڵ�ջΪ�ջ�ڵ�ΪNULLʱ����ѭ��
		while (node != NULL) {	//�����Ӳ�Ϊ��ʱ
			nodes.push(node);	//�ڵ���ջ
			cout << node->data << " ";	//��ӡ�ڵ�
			node = node->leftChild;	//ָ��ǰ�ڵ�����
		}
		node = nodes.top();	//���ݵ����ڵ�
		nodes.pop();	//���ڵ��ջ
		node = node->rightChild;	//ָ�򸸽ڵ��Һ���
	}
}

// �ݹ��������
void inorderBiTree(BiTree tree)
{
	if (tree)
	{
		inorderBiTree(tree->leftChild);
		cout << visit(tree) << " ";
		inorderBiTree(tree->rightChild);
	}
}

// �ǵݹ��������
void inorderBiTreeNonRecursive(BiTree tree) {
	if (tree == NULL)
		return;
	BiTree node = tree;
	stack<BiTree> nodes;
	while (node || !nodes.empty()) {
		while (node != NULL) {
			nodes.push(node);
			node = node->leftChild;
		}
		node = nodes.top();
		cout << node->data << " ";
		nodes.pop();
		node = node->rightChild;
	}
}

// �ݹ�������
void postorderBiTree(BiTree tree)
{
	if (tree)
	{
		postorderBiTree(tree->leftChild);
		postorderBiTree(tree->rightChild);
		cout << visit(tree) << " ";
	}
}

// �ǵݹ�������
void postorderBiTreeNonRecursive(BiTree tree) {
	cout << "�����..." << endl;
}

int main()
{
	BiTree tree = createBiTree();
	cout << "ǰ��ݹ�������Ϊ:";
	preorderBiTree(tree);
	cout << endl;
	cout << "ǰ��ǵݹ�������Ϊ:";
	preorderBiTreeNonRecursive(tree);
	cout << endl;
	cout << "����������Ϊ:";
	inorderBiTree(tree);
	cout << endl;
	cout << "����ǵݹ�������Ϊ:";
	inorderBiTreeNonRecursive(tree);
	cout << endl;
	cout << "����������Ϊ:";
	postorderBiTree(tree);
	cout << endl;
	exchange(tree);
	cout << endl << "���������ѽ���" << endl;
	cout << "������ǰ��������Ϊ:";
	preorderBiTree(tree);
	cout << endl;
	cout << "����������������Ϊ:";
	inorderBiTree(tree);
	cout << endl;
	cout << "���������������Ϊ:";
	postorderBiTree(tree);
	cout << endl;
	return 0;
}