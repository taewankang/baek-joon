#include<iostream>
using namespace std;

int sum(int N) {
	int result = 0;
	for (int i = 1; i <= N; i++) {
		result += i;
	}
	return result;
}

int main(void) {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int n;
		cin >> n;
		int result = 0;
		for (int j = 1; j <= n; j++) {
			result += j * sum(j + 1);
		}
		cout << result << "\n";
	}
	system("pause");
	return 0;
}