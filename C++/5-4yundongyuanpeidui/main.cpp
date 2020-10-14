#include<stdio.h>
#include<stdlib.h>

#define N 100
int n;
int P[N][N], Q[N][N], x[N];
int tempValue = 0, maxValue = 0;

void compute() {
	tempValue = 0;
	for (int i = 1; i <= n; i++) {
		tempValue += P[i][x[i]] * Q[x[i]][i];
	}
	if (tempValue > maxValue) {
		maxValue = tempValue;
	}
}

void TB(int t) {
	int i, j, temp;
	if (t > n) {
		compute();
	}
	for (i = t; i <= n; i++) {
		temp = x[i];
		x[i] = x[t];
		x[t] = temp;
		TB(t + 1);
		temp = x[i];
		x[i] = x[t];
		x[t] = temp;
	}
}
int main() {
	scanf_s("%d", &n);

	for (int i = 1; i <= n; i++) {
		x[i] = i;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf_s("%d", &P[i][j]);
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf_s("%d", &Q[i][j]);
		}
	}
	TB(1);
	printf("%d\n", maxValue);
	return 0;
}