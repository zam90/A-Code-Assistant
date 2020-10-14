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
// 文件名称：Stack.h
// 项目名称：Calculator
// 创建者：张京宇
// 创建时间：2019.10.6
// 最后修改时间：2019.10.15
// 功能：堆栈类

//用单链表实现堆栈操作
#ifndef STACK__H__
#define STACK__H__

//导入库文件
#include <iostream>

enum errorcode{ success, overflow, underflow ,wrong};
using namespace std; //使用标准命名空间

template<class T>
struct Node//构建节点类 
{
	Node(const T &da, Node* p);
	T data;
	Node *next;
};

template<class T>
Node<T>::Node(const T &da, Node* p)
{
	data = da;
	next = p;
}

template<class T>
class Stack
{
public:
	Stack();//初始化链表 
	~Stack();//析构 
	void clean();//清空链表 
	errorcode push(const T da);//压栈 
	T pop();//弹出
	T top();//查看栈顶
	bool isempty();//判断单链表是否为空 
public:
	int len;
private:
	Node<T> *head;
};

template<class T>
Stack<T>::Stack()
{
	head = NULL;
	len = 0;
}

template<class T>
Stack<T>::~Stack()
{
	clean();
}

template<class T>
void Stack<T>::clean()//清空链表 
{
	Node<T>* p = head, *q;
	while (p)
	{
		q = p->next;
		delete p;
		p = q;
	}
	head = NULL;
	len = 0;
}

template<class T>
errorcode Stack<T>::push(const T da)
{
	Node<T>* p = head;
	Node<T>* q = new Node<T>(da, p);
	if (NULL == q)
		return overflow;
	head = q;
	len++;
	return success;
}

template<class T>
T Stack<T>::pop()
{
	if (0 == len || NULL == head)
		exit(1);//非正常结束
	T temp = head->data;
	head = head->next;
	len--;
	return temp;
}

template<class T>
T Stack<T>::top()
{
	if (0 == len || NULL == head)
		exit(1);//非正常结束
	return head->data;
}

template<class T>
bool Stack<T>::isempty()
{
	return (0 == len);
}

#endif

