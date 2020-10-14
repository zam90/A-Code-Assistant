#include "main.h"

int main()
{
	RandomDouble();
	int i, j, p;
	double a[N];
	Fileindouble(a);
	SheelSortdouble(a, N);
	Fileoutdouble(a);
	cout << "程序结束！\n";
	cin.get();//暂停窗口，等待指令
}