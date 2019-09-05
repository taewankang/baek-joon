#include<iostream>
#include<stdio.h>
using namespace std;
int main(void) {
	double N, B, M;
	while (~scanf_s("%lf %lf %lf", &N, &B, &M)) {
		int count = 0;
		while (N <= M) {
			N += (N*(B/100));
			count++;
		}
		cout << count << "\n";

	}

	system("pause");
	return 0;
}