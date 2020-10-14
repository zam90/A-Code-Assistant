// Honer Code
// 我真诚地保证：
// 我自己独立地完成了整个程序从分析、设计到编码的所有工作。
// 如果在上述过程中，我遇到了什么困难而求教于人，那么，我将在程序实习报告中
// 详细地列举我所遇到的问题，以及别人给我的提示。
// 我的程序里中凡是引用到其他程序或文档之处，
// 例如教材、课堂笔记、网上的源代码以及其他参考书上的代码段,
// 我都已经在程序的注释里很清楚地注明了引用的出处。
// 我从未没抄袭过别人的程序，也没有盗用别人的程序，
// 不管是修改式的抄袭还是原封不动的抄袭。
// 我编写这个程序，从来没有想过要去破坏或妨碍其他计算机系统的正常运转。
// 签署人：计类1801 张京宇 2018011140

// 程序文档
// 文件名称：tree.cpp
// 项目名称：Tree
// 创建者：张京宇
// 创建时间：2019.11.4
// 最后修改时间：2019.11.5
// 功能：二叉树建立与遍历主程序

#include <iostream>	//导入IO库文件
#include <string.h>
#include <assert.h>
#include <stack>
#define N 15	//N为节点数
using namespace std;	//使用标准命名空间

//定义节点类
class node
{
public:
	int data;	//节点信息
	node* leftChild;//节点指针：左孩子
	node* rightChild;//节点指针：右孩子
};
typedef node* BiTree;//等价，定义node*的新名字BiTree

//创建节点，加*号的意义：返回类型指针型数据
node* createNode(int value)
{
	node* q = new node;
	q->leftChild = NULL;	//leftChild指针为空
	q->rightChild = NULL;	//rightChild指针为空
	q->data = value;	//节点值等于value
	return q;	//返回节点
}

//建立二叉树
BiTree createBiTree()
{
	node* p[N] = { NULL };
	//int array[28] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27 };//默认建立28节点二叉树
	//自左向右输入节点值生成二叉树
	cout<<"请按自左向右顺序输入二叉树各节点:"<<endl;	//提示语
	int array[N];	//定义array数组用于存储节点信息
	for (int i = 0; i < N; ++i){
		cin >> array[i];	//储存输入节点的值
	}
	for (int i = 0; i < N; ++i)
		p[i] = createNode(array[i]);	//创建节点
	for (int i = 0; i < N / 2; i++)
	{
		p[i]->leftChild = p[i * 2 + 1];	//赋予每个节点左孩子指针
		p[i]->rightChild = p[i * 2 + 2];	//赋予每个节点右孩子指针
	}
	return p[0];
}

//访问节点中的数据
int visit(BiTree tree)
{
	return tree->data;	//返回节点的值
}

//递归交换二叉树中的左右子树
void exchange(BiTree tree)
{
	BiTree temp;	//创建中间二叉树
	if (tree) {
		temp = tree->leftChild;	//中间二叉树储存所需交换二叉树的左孩子
		tree->leftChild = tree->rightChild;	//将所需交换二叉树右孩子的值赋予左孩子
		tree->rightChild = temp;	//将中间二叉树储存的值赋予所需交换二叉树右孩子
		//类似于a,b两个数互换值，取中间变量c
		exchange(tree->leftChild);	//递归交换左孩子的值
		exchange(tree->rightChild);	//没有左孩子时，递归交换右孩子的值
	}
}

// 递归前序遍历
void preorderBiTree(BiTree tree)
{
	if (tree)
	{
		cout << visit(tree) << " ";	//打印当前节点值
		preorderBiTree(tree->leftChild);	//遍历左孩子
		preorderBiTree(tree->rightChild);	//没有左孩子时，遍历右孩子
	}
}

// 非递归前序遍历
void preorderBiTreeNonRecursive(BiTree tree) {
	if (tree == NULL)
		return;
	BiTree node = tree;	//创建节点
	stack<BiTree> nodes;	//创建节点栈
	while (node || !nodes.empty()) {	//当节点栈为空或节点为NULL时结束循环
		while (node != NULL) {	//当左孩子不为空时
			nodes.push(node);	//节点入栈
			cout << node->data << " ";	//打印节点
			node = node->leftChild;	//指向当前节点左孩子
		}
		node = nodes.top();	//回溯到父节点
		nodes.pop();	//父节点出栈
		node = node->rightChild;	//指向父节点右孩子
	}
}

// 递归中序遍历
void inorderBiTree(BiTree tree)
{
	if (tree)
	{
		inorderBiTree(tree->leftChild);
		cout << visit(tree) << " ";
		inorderBiTree(tree->rightChild);
	}
}

// 非递归中序遍历
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

// 递归后序遍历
void postorderBiTree(BiTree tree)
{
	if (tree)
	{
		postorderBiTree(tree->leftChild);
		postorderBiTree(tree->rightChild);
		cout << visit(tree) << " ";
	}
}

// 非递归后序遍历
void postorderBiTreeNonRecursive(BiTree tree) {
	cout << "待解决..." << endl;
}

int main()
{
	BiTree tree = createBiTree();
	cout << "前序递归遍历结果为:";
	preorderBiTree(tree);
	cout << endl;
	cout << "前序非递归遍历结果为:";
	preorderBiTreeNonRecursive(tree);
	cout << endl;
	cout << "中序遍历结果为:";
	inorderBiTree(tree);
	cout << endl;
	cout << "中序非递归遍历结果为:";
	inorderBiTreeNonRecursive(tree);
	cout << endl;
	cout << "后序遍历结果为:";
	postorderBiTree(tree);
	cout << endl;
	exchange(tree);
	cout << endl << "左右子树已交换" << endl;
	cout << "交换后前序遍历结果为:";
	preorderBiTree(tree);
	cout << endl;
	cout << "交换后中序遍历结果为:";
	inorderBiTree(tree);
	cout << endl;
	cout << "交换后后序遍历结果为:";
	postorderBiTree(tree);
	cout << endl;
	return 0;
}