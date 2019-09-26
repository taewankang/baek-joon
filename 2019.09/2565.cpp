#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int N, A, B;
	cin >> N;
	vector<pair<int, int>> vec(N);
	vector<int> dp(N, 1);
	for (int i = 0; i < N; i++) {
		cin >> A >> B;
		vec[i] = { A, B };
	}
	sort(vec.begin(), vec.end());

	for (int i = 1; i < N; i++) {
		for (int j = 0; j < i; j++) {
			if (vec[i].second > vec[j].second && dp[j] + 1 > dp[i])
				dp[i]++;
		}
	}
	int maximum = 0;
	for (int i = 0; i < N; i++)
		if (dp[i] > maximum)
			maximum = dp[i];
	cout << N - maximum << endl;
	system("pause");
	return 0;
}