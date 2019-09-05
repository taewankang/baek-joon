#include<iostream>
using namespace std;
bool prime(int N) {
	if (N == 1)
		return false;
	for (int i = 2; i*i <= N; i++) {
		if (N%i == 0)
			return false;
	}
	return true;
}

int main(void) {
	int M, N, minimum = 0;
	long long result = 0;
	cin >> M >> N;
	bool min = false;
	for (int i = M; i <= N; i++) {
		if (prime(i)) {
			if (min == false) {
				minimum = i;
				min = true;
			}
			result += i;
		}
	}
	if (result != 0) {
		cout << result << endl;
		cout << minimum << endl;
	}
	else
		cout << "-1\n";

	system("pause");
	return 0;
}