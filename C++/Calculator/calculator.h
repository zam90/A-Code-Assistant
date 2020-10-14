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
// 文件名称：calculator.h
// 项目名称：Calculator
// 创建者：张京宇
// 创建时间：2019.10.6
// 最后修改时间：2019.10.15
// 功能：计算器类头文件声明

#ifndef CALCULATOR__H__
#define CALCULATOR__H__

//导入堆栈头文件
#include "Stack.h"
#include <cstdlib>

using namespace std;//使用标准命名空间

//计算器类，仅作声明
class Calculator
{
public:
	Calculator();
	~Calculator();
	errorcode setnull();
	double show();
	errorcode run();//计算过程 
	double operate(char op,double a,double b); 
	bool error(char op,char ch);//识别各种错误
	double double_type(double a);
private:
	Stack<double> opnd;
	Stack<char> optr;
	double value;
	int lp(char op);//右优先度 
	int rp(char op);//左优先度 
};

#endif
