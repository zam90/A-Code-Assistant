#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <string.h>
#include <fstream>
using namespace std;
int t = 0;

template<class Type>
void Swap(Type& a, Type& b)
{
	char temp = a;
	a = b;
	b = temp;
}

template<class Type>
int Jud(Type* a, int k, int i)
{
	if (i > k)
		for (int t = k; t < i; t++)
		{
			if (a[t] == a[i])
				return 0;
		}
	return 1;
}

template<class Type>
void Perm(Type* a, int k, int m)
{
	if (k == m)
	{
		t++;
		for (int i = 0; i <= m; i++)
		{
			ofstream outfile("output.txt");
			outfile << a[i] << endl;
			outfile.close();
		}
	}
	else
	{
		for (int i = k; i <= m; i++)
		{
			if (Jud(a, k, i))
			{
				Swap(a[k], a[i]);
				Perm(a, k + 1, m);
				Swap(a[k], a[i]);
			}
		}
	}
}
int main()
{
	int n = 0;
	ifstream infile;
	infile.open("input.txt");
	while (!infile.eof())
	{
		cin >> n;
		cin.ignore(1024, '\n');
	}
	char* a = new char[n];
	while (!infile.eof())
	{
		cin >> a;
		cin.ignore(1024, '\n');
	}
	infile.close();
	Perm(a, 0, n - 1);
	ofstream outfile("output.txt");
	outfile << t << endl;
	outfile.close();
	delete[] a;
	return 0;
}