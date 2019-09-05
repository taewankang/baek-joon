#include<iostream>
using namespace std;
int prime(int n) {
	int result = 0;
	if (n == 1) {
		return 1;
	}
	for (int i = n + 1; i <= n * 2; i++) {
		bool pr = true;
		for (int k = 2; k*k <= i; k++) {
			if (i%k == 0) {
				pr = false;
				break;
			}
		}
		if (pr == true)
			result++;
	}
	return result;
}

int main(void) {
	int N;
	while (1) {
		scanf_s("%d", &N);
		if (N == 0)
			break;
		printf("%d\n", prime(N));
	}
	system("pause");
	return 0;
}