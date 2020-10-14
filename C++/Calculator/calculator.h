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
// �ļ����ƣ�calculator.h
// ��Ŀ���ƣ�Calculator
// �����ߣ��ž���
// ����ʱ�䣺2019.10.6
// ����޸�ʱ�䣺2019.10.15
// ���ܣ���������ͷ�ļ�����

#ifndef CALCULATOR__H__
#define CALCULATOR__H__

//�����ջͷ�ļ�
#include "Stack.h"
#include <cstdlib>

using namespace std;//ʹ�ñ�׼�����ռ�

//�������࣬��������
class Calculator
{
public:
	Calculator();
	~Calculator();
	errorcode setnull();
	double show();
	errorcode run();//������� 
	double operate(char op,double a,double b); 
	bool error(char op,char ch);//ʶ����ִ���
	double double_type(double a);
private:
	Stack<double> opnd;
	Stack<char> optr;
	double value;
	int lp(char op);//�����ȶ� 
	int rp(char op);//�����ȶ� 
};

#endif
