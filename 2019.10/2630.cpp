#include<iostream>
#include<vector>
using namespace std;
int white = 0, blue = 0;
vector<vector<int>> vec(129);
void recursive(int y, int x, int size) {
	bool same = true;
	if (size == 1) {
		if (vec[y][x] == 0)
			white++;
		else
			blue++;
		return;
	}
	for (int i = y; i < y + size; i++) {
		for (int j = x; j < x + size; j++) {
			if (vec[y][x] != vec[i][j]) {	//다르다면
				same = false;
				break;
			}
		}
		if (same == false)
			break;
	}
	if (same == true) {
		if (vec[y][x] == 0)
			white++;
		else
			blue++;
	}
	else {
		recursive(y, x, size / 2);
		recursive(y, x + size / 2, size / 2);
		recursive(y + size / 2, x, size / 2);
		recursive(y + size / 2, x + size / 2, size / 2);
	}
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

	recursive(1, 1, N / 2);
	recursive(N / 2 + 1, N / 2 + 1, N / 2);
	recursive(1, N / 2 + 1, N / 2);
	recursive(N / 2 + 1, 1, N / 2);
	cout << white << endl << blue << endl;
	system("pause");
	return 0;
}