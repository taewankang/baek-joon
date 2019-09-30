#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int arr[101][100001] = { 0, };
int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int N, K, weight, value;
	cin >> N >> K;

	vector<int> vec(N + 1);
	vector<int> val(N + 1);

	for (int i = 1; i <= N; i++) {
		cin >> weight >> value;
		vec[i] = weight;
		val[i] = value;
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= K; j++) {
			arr[i][j] = max(arr[i - 1][j], arr[i][j - 1]);
			if (j - vec[i] >= 0) {
				arr[i][j] = max(arr[i][j], arr[i - 1][j - vec[i]] + val[i]);
			}
		}
	}

	cout << arr[N][K] << endl;
	system("pause");
	return 0;
}

