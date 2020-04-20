/*
	Á¡È­½Ä: DP[K][N] = DP[K - 1][N - vec[K - 1]] + DP[k - 1][N + vec[K - 1]]
*/

#include<iostream>
#include<vector>
using namespace std;
long long N, dp[101][21] = { 0, };
vector<int> vec;

void input() {
	int n;
	for (int i = 0; i < N; i++) {
		cin >> n;
		vec.push_back(n);
	}
}

void make_dp() {
	dp[0][vec[0]] = 1;
	for (int i = 0; i < N - 2; i++) {
		for (int j = 0; j < 21; j++) {
			if (dp[i][j]) {
				j - vec[i + 1] >= 0 ? dp[i + 1][j - vec[i + 1]] += dp[i][j] : NULL;
				j + vec[i + 1] <= 20 ? dp[i + 1][j + vec[i + 1]] += dp[i][j] : NULL;
			}
		}
	}
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> N;
	input();
	make_dp();
	cout << dp[N - 2][vec[N - 1]] << endl;
	return 0;
}