#include<iostream>
#include<stdio.h>
using namespace std;
int main(void) {
	int C, K, P, result=0;
	scanf("%d %d %d", &C,&K, &P);
	result = K * ((C*(C + 1)) / 2) + P * ((C*(C + 1)*(2 * C + 1)) / 6);
	printf("%d\n", result);
	system("pause");
	return 0;
}