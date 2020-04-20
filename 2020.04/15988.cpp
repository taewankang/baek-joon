#include<iostream>
using namespace std;
int T, N;
long long dp[1000001] = { 0, };

void make_dp() {
	dp[1] = 1; dp[2] = 2; dp[3] = 4;
	for (int i = 4; i < 1000001; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % 1000000009;
	}
}


int main(void) {
	cin >> T;
	make_dp();
	for (int t = 0; t < T; t++) {
		cin >> N;
		cout << dp[N] << "\n";
	}
	return 0;
}
