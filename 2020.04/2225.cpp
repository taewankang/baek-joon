/*
	Á¡È­½Ä: DP[N][K] = ¥Ò(k = 0 ~ N) DP[N - 1][k]
*/

#include<iostream>
using namespace std;
int N, K;
int arr[201][201] = { 0, };
int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> N >> K;

	for (int i = 1; i <= N; i++)
		arr[1][i] = 1;

	for (int i = 0; i <= K; i++)
		arr[i][0] = 1;

	for (int i = 1; i <= K; i++) {
		for (int j = 1; j <= N; j++) {
			arr[i][j] = (arr[i - 1][j] + arr[i][j - 1]) % 1000000000;
		}
	}

	cout << arr[K][N] << endl;
	return 0;
}