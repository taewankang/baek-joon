#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
#include<string>
using namespace std;
int main(void) {
	int N, M;
	string str;
	cin >> N >> M;
	vector<vector<int>> vec(N);
	for (int i = 0; i < N; i++) {
		cin >> str;
		for (int j = 0; j < M; j++) {
			vec[i].push_back(str[j] - '0');
		}
	}
	int max_square = min(M, N);
	while (max_square >= 1) {
		for (int i = 0; i + max_square - 1 < N; i++) {
			for (int j = 0; j + max_square - 1 < M; j++) {
				if ((vec[i][j] == vec[i][j + max_square - 1]) && (vec[i][j] == vec[i + max_square - 1][j]) && (vec[i][j + max_square - 1] == vec[i + max_square - 1][j + max_square - 1])) {
					cout << max_square * max_square << "\n";
					system("pause");
					return 0;
				}
			}
		}
		max_square--;
		if (max_square == 1) {
			cout << "1\n";
			break;
		}
	}
	system("pause");
	return 0;
}