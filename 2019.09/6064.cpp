#include<iostream>
using namespace std;
int T, M, N, x, y;
int calender() {
	int num = 0;
	for (int i = 0; i < N; i++) {
		num = M * i + x;
		if (num % N == y)
			return num;
		if (y == N && num % N == 0) {
			return num;
		}
	}
	return -1;
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> M >> N >> x >> y;
		cout << calender() << "\n";
	}
	system("pause");
	return 0;
}