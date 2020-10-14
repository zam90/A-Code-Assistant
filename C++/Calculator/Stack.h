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
// �ļ����ƣ�Stack.h
// ��Ŀ���ƣ�Calculator
// �����ߣ��ž���
// ����ʱ�䣺2019.10.6
// ����޸�ʱ�䣺2019.10.15
// ���ܣ���ջ��

//�õ�����ʵ�ֶ�ջ����
#ifndef STACK__H__
#define STACK__H__

//������ļ�
#include <iostream>

enum errorcode{ success, overflow, underflow ,wrong};
using namespace std; //ʹ�ñ�׼�����ռ�

template<class T>
struct Node//�����ڵ��� 
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
	Stack();//��ʼ������ 
	~Stack();//���� 
	void clean();//������� 
	errorcode push(const T da);//ѹջ 
	T pop();//����
	T top();//�鿴ջ��
	bool isempty();//�жϵ������Ƿ�Ϊ�� 
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
void Stack<T>::clean()//������� 
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
		exit(1);//����������
	T temp = head->data;
	head = head->next;
	len--;
	return temp;
}

template<class T>
T Stack<T>::top()
{
	if (0 == len || NULL == head)
		exit(1);//����������
	return head->data;
}

template<class T>
bool Stack<T>::isempty()
{
	return (0 == len);
}

#endif

