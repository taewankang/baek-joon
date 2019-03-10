#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(void) {
	int T, N, n;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N;
		vector<vector<pair<int, int>>> vec(2);
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < N; k++) {
				cin >> n;
				vec[j].push_back({ n, 0 });
			}
		}
		vec[0][0].second = vec[0][0].first;
		vec[1][0].second = vec[1][0].first;
		vec[0][1].second = vec[1][0].second + vec[0][1].first;
		vec[1][1].second = vec[0][0].second + vec[1][1].first;
		for (int k = 2; k < N; k++) {
			for (int j = 0; j < 2; j++) {
				if (j == 0) {
					vec[0][k].second = vec[0][k].first + max(vec[0][k - 2].second, max(vec[1][k-2].second, vec[1][k-1].second));
				}
				else {
					vec[1][k].second = vec[1][k].first + max(vec[1][k - 2].second, max(vec[0][k - 2].second, vec[0][k - 1].second));
				}
			}
		}
		int maximum = max(max(vec[0][N - 1].second, vec[1][N - 1].second), max(vec[0][N - 2].second, vec[1][N - 2].second));
		cout << maximum << endl;
	}
	system("pause");
	return 0;
}