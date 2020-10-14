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
// �ļ����ƣ�calculator.cpp
// ��Ŀ���ƣ�Calculator
// �����ߣ��ž���
// ����ʱ�䣺2019.10.6
// ����޸�ʱ�䣺2019.10.15
// ���ܣ���������

#include "calculator.h"

Calculator::Calculator()  // ��������
{
	optr.clean();
	opnd.clean(); 
	optr.push('#');
}


Calculator::~Calculator() // ��������
{
}

errorcode Calculator::setnull() // �����󣬳�ʼ��calculator
{
	optr.clean();
	opnd.clean();
	return optr.push('#');
}

double Calculator::show() // ��ʾ������
{
	return value;
}

errorcode Calculator::run() // ���м���
{
	char ch,op,ope;
	double val,a,b;
	bool lastisdig = false;
	bool lastisdot = false;
	op = '#';
	cin >> ch;
	while (ch!='#'||op!='#')
	{
		if (error(op, ch))
			return wrong;	
		if ('.'==ch)
		{
			lastisdot = true;
			cin >> ch;
			continue;
		}
		else if (isdigit(ch))
		{
			cin.putback(ch);
			cin >> val;
			if (true == lastisdig)//�������������Ϊһ��
			{
				if (true == lastisdot)
				{
					double integer = opnd.pop();
					val = integer + double_type(val);
				}
				else
				{
				}
			}
			opnd.push(val);
			lastisdig = true;
			lastisdot = false;
			cin >> ch;
		}
		else if (lp(op)<rp(ch)) // �������ȼ��Ƚ�
		{
			optr.push(ch);
			op = ch;
			lastisdig = false;
			lastisdot = false;
			cin >> ch;
		}
		else if (lp(op)==rp(ch)) // �������ȼ��Ƚ�
		{
			optr.pop();
			op = optr.top();
			lastisdig = false;
			lastisdot = false;
			cin >> ch;
		}
		else // �������ȼ��Ƚ�
		{
			ope = optr.pop();
			b = opnd.pop();
			a = opnd.pop();
			opnd.push(operate(ope, a, b));
			op = optr.top();
			lastisdig = false;
			lastisdot = false;
		}
	}
	value = opnd.top();
	return success;
}

double Calculator::operate(char op, double a, double b) // ��������������
{
	switch (op)
	{
	case '+':return a + b; break;
	case '-':return a - b; break;
	case '*':return a * b; break;
	case '/':if (b == 0){
		cout << "��ĸ����Ϊ0" << endl; 
		exit(1);
	} 
	else return (a / b); break;
	default:exit(1); break;
	}
}

int Calculator::lp(char op) // �����ȼ�
{
	switch (op)
	{
	case '+':return 2; break;
	case '-':return 3; break;
	case '*':return 4; break;
	case '/':return 5; break;
	case '(':return 1; break;
	case ')':return 6; break;
	case '#':return 0; break;
	default:return -1; break;
	}
}

int Calculator::rp(char op) // �����ȼ�
{
	switch (op)
	{
	case '+':return 3; break;
	case '-':return 2; break;
	case '*':return 5; break;
	case '/':return 4; break;
	case '(':return 6; break;
	case ')':return 1; break;
	case '#':return 0; break;
	default:return -1; break;
	}
}

bool Calculator::error(char op, char ch) // �жϸ��ִ������ͣ������ȼ��ж�
{
	if (1 == lp(op) && 0 == rp(ch))
		return true;
	if (6 == lp(op) && 6 == rp(ch))
		return true;
	if (0 == lp(op) && 1 == rp(ch))
		return true;
	if (4 == lp(op) && 0 == rp(ch))
		return true;
	return false;
}

double Calculator::double_type(double a)
{
	while (a >= 1)
		a /= 10;
	return a;
}

