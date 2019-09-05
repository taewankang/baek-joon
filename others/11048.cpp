#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(void) {
	int N, M;
	cin >> N >> M;
	vector<vector<int>> vec(N);
	int n;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> n;
			vec[i].push_back(n);
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (i == 0 && j == 0) {
				continue;
			}
			else if (i == 0) {
				vec[i][j] += vec[i][j - 1];
			}
			else if (j == 0) {
				vec[i][j] += vec[i - 1][j];
			}
			else if (i > 0 && j > 0) {
				vec[i][j] += max(vec[i][j - 1], max(vec[i - 1][j], vec[i - 1][j - 1]));
			}
		}
	}

	cout << vec[N - 1][M - 1] << endl;
	system("pause");
	return 0;
}