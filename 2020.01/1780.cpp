#include<iostream>
#include<queue>
#include<string.h>
#include<string>
using namespace std;
int arr[3] = { 0, 0, 0 };
vector<vector<int>> vec(2188);

bool check(int y, int x, int size) {
	int first_num = vec[y][x];
	for (int i = y; i < y + size; i++) {
		for (int j = x; j < x + size; j++) {
			if (vec[i][j] != first_num)
				return false;
		}
	}
	return true;
}

void start(int y, int x, int size) {
	if (check(y, x, size)) {
		if (vec[y][x] == -1)	arr[0]++;
		else if (vec[y][x] == 0)	arr[1]++;
		else if (vec[y][x] == 1)	arr[2]++;
		return;
	}
	if (size == 1)
		return;

	start(y, x, size / 3);
	start(y, x + size / 3, size / 3);
	start(y, x + (size / 3) * 2, size / 3);
	start(y + size / 3, x, size / 3);
	start(y + size / 3, x + size / 3, size / 3);
	start(y + size / 3, x + (size / 3) * 2, size / 3);
	start(y + (size / 3) * 2, x, size / 3);
	start(y + (size / 3) * 2, x + size / 3, size / 3);
	start(y + (size / 3) * 2, x + (size / 3) * 2, size / 3);
}
int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int N, n;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		vec[i].push_back(0);
		for (int j = 1; j <= N; j++) {
			cin >> n;
			vec[i].push_back(n);
		}
	}

	start(1, 1, N);
	cout << arr[0] << "\n" << arr[1] << "\n" << arr[2] << "\n";

	system("pause");
	return 0;
}