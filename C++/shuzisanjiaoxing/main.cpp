#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#define H 5	//数字三角形行数

using namespace std;

int main() {
	int i = 0, j = 0, m = 0;
	for (i = H; i > 0; i--) {
		m = m + i;
	}
	int sanjiao[99][99];
	printf("请输入三角形中的数字：\n");
	for (i = 0; i <= H - 1; i++) {
		for (j = 0; j <= i; j++) {
			cin >> sanjiao[i][j];
		}
	}
	int count = 0;
	int result[999] = {0};
	for (int i = H - 2; i >= 0; i--) {
		for (int j = 0; j < i + 1; j++) {
			result[j] = sanjiao[i][j] + min(result[j], result[j + 1]);
		}
	}
	cout << result[0];
	return 0;
}