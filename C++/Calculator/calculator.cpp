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
// 文件名称：calculator.cpp
// 项目名称：Calculator
// 创建者：张京宇
// 创建时间：2019.10.6
// 最后修改时间：2019.10.15
// 功能：计算器类

#include "calculator.h"

Calculator::Calculator()  // 构建函数
{
	optr.clean();
	opnd.clean(); 
	optr.push('#');
}


Calculator::~Calculator() // 析构函数
{
}

errorcode Calculator::setnull() // 遇错误，初始化calculator
{
	optr.clean();
	opnd.clean();
	return optr.push('#');
}

double Calculator::show() // 显示计算结果
{
	return value;
}

errorcode Calculator::run() // 运行计算
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
			if (true == lastisdig)//两部分数字组合为一个
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
		else if (lp(op)<rp(ch)) // 左右优先级比较
		{
			optr.push(ch);
			op = ch;
			lastisdig = false;
			lastisdot = false;
			cin >> ch;
		}
		else if (lp(op)==rp(ch)) // 左右优先级比较
		{
			optr.pop();
			op = optr.top();
			lastisdig = false;
			lastisdot = false;
			cin >> ch;
		}
		else // 左右优先级比较
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

double Calculator::operate(char op, double a, double b) // 计算器操作函数
{
	switch (op)
	{
	case '+':return a + b; break;
	case '-':return a - b; break;
	case '*':return a * b; break;
	case '/':if (b == 0){
		cout << "分母不能为0" << endl; 
		exit(1);
	} 
	else return (a / b); break;
	default:exit(1); break;
	}
}

int Calculator::lp(char op) // 左优先级
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

int Calculator::rp(char op) // 右优先级
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

bool Calculator::error(char op, char ch) // 判断各种错误类型，用优先级判断
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

