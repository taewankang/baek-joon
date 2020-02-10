#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, t, p, result = 0;
	cin >> N;
	vector<int> T(N + 1), P(N + 1), dp(N + 1, 0);
	int arr[16][16] = { 0, };
	for (int i = 1; i <= N; i++) {
		cin >> t >> p;
		T[i] = t;
		P[i] = p;
	}

	for (int i = 1; i <= N; i++) {
		if (i + T[i] - 1 <= N)
			arr[i][i + T[i] - 1] = -1;
	}

	for (int i = 1; i <= N; i++) {		//가로
		for (int j = 1; j <= i; j++) {		//세로
			if (arr[j][i] == -1) {
				dp[i] = max(max(dp[i], dp[i - T[j]] + P[j]), dp[i - 1]);
			}
			if (j == i && dp[i] == 0)
				dp[i] = dp[i - 1];
		}
	}

	cout << dp[N] << endl;
	system("pause");
	return 0;
}