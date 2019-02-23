#include<iostream>
using namespace std;
int decomposition(int N) {
	int copy_N = N;
	while (copy_N >= 1) {
		N += copy_N % 10;
		copy_N /= 10;
	}
	return N;
}

int main(void) {
	int N;
	cin >> N;
	int copy_N = N;
	int length = 0;
	bool find = false;
	while (copy_N >= 1) {
		copy_N /= 10;
		length++;
	}
	for (int i = N - (9 * length); i <= N; i++) {
		if (decomposition(i) == N) {
			cout << i << endl;
			find = true;
			break;
		}
	}
	if (find == false)
		cout << "0\n";

	system("pause");
	return 0;
}