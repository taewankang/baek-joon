/*
	Á¡È­½Ä: DP[K][N] = DP[K - 1][N - vec[K - 1]] + DP[k - 1][N + vec[K - 1]]
*/

#include<iostream>
#include<vector>
using namespace std;
int N;
vector<int> vec(101);
long long arr[101][21] = { 0, };
int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> vec[i];

	arr[1][vec[1]] = 1;
	for (int i = 2; i < N; i++) {
		for (int j = 0; j <= 20; j++) {
			if (arr[i - 1][j] != 0) {
				if (j - vec[i] >= 0)
					arr[i][j - vec[i]] += arr[i - 1][j];
				if (j + vec[i] <= 20)
					arr[i][j + vec[i]] += arr[i - 1][j];
			}
		}
	}

	cout << arr[N - 1][vec[N]] << endl;

	return 0;
}