#include<iostream>
#include<stdio.h>
using namespace std;
int main(void) {
	int fac[6];
	fac[1] = 1;
	int N;
	for (int i = 1; i < 5; i++) {
		fac[i + 1] = fac[i] * (i + 1);
	}
	while (1) {
		scanf("%d", &N);
		int result = 0;
		int j = 1;
		if (N == 0)
			break;
		while (N >= 1) {
			result += (N % 10)*fac[j];
			j++;
			N /= 10;
		}
		printf("%d\n", result);
	}
	system("pause");
	return 0;
}