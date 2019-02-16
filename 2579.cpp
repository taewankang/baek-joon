#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(void) {
	int N, n;
	cin >> N;
	vector<int> vec(10001);
	vector<int> dp(10001);
	fill(vec.begin(), vec.end(), 0);
	fill(dp.begin(), dp.end(), 0);

	for (int i = 0; i < N; i++) {
		cin >> n;
		vec[i]=n;
	}
	reverse(vec.begin(), vec.begin()+N);

	dp[0] = vec[0];
	dp[1] = vec[0] + vec[1];
	dp[2] = vec[0] + vec[2];

	for (int i = 3; i < N; i++) {
		dp[i] = max(dp[i - 3] + vec[i] + vec[i-1], dp[i - 2] + vec[i]);
	}
	cout << max(dp[N - 1], dp[N - 2])<<endl;
	system("pause");
	return 0;
}