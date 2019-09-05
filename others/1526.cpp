#include<iostream>
using namespace std;
int find(int N) {
	int copy_N = N;
	while (N >= 1) {
		if (N % 10 != 4 && N % 10 != 7) {
			return -1;
		}
		N /= 10;
	}
	return copy_N;
}

int main(void) {
	int N;
	cin >> N;
	for (int i = N; i >= 0; i--) {
		if (find(i) != -1) {
			cout << i << "\n";
			break;
		}
	}
	system("pause");
	return 0;
}