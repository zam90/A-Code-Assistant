#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

template <class T>
void sort(T a[])
{
	int i, j;
	T t;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3 - i; j++)
		{
			if (a[j] < a[j + 1])
			{
				t = a[j + 1];
				a[j + 1] = a[j];
				a[j] = t;
			}
		}
	}
}


int main(){
	int arr1[3];
	double arr2[3];
	long arr3[3];
	for (int i = 0; i < 3; i++) {
		cin >> arr1[i];
	}
	for (int i = 0; i < 3; i++) {
		cin >> arr2[i];
	}
	for (int i = 0; i < 3; i++) {
		cin >> arr3[i];
	}
	sort(arr1);
	sort(arr2);
	sort(arr3);
	for (int i = 0; i < 3; i++)
	{
		cout << arr1[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << arr2[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << arr3[i] << " ";
	}
}