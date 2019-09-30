#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int arr[2][10001] = { 0, };
int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int N, k, n;
	cin >> N >> k;
	vector<int> vec(N + 1);
	arr[0][0] = 1;
	arr[1][0] = 1;
	for (int i = 1; i <= N; i++) {
		cin >> n;
		vec[i] = n;
	}

	for (int i = vec[1]; i <= k; i++) 
		if (i % vec[1] == 0)
			arr[1][i] = 1;

	for (int i = 2; i <= N; i++) {
		for (int j = 1; j <= k; j++) {
			if (i % 2 == 0) {		//짝수
				if (j < vec[i])
					arr[0][j] = arr[1][j];
				else
					arr[0][j] = arr[1][j] + arr[0][j - vec[i]];
			}
			else {
				if (j < vec[i])
					arr[1][j] = arr[0][j];
				else
					arr[1][j] = arr[0][j] + arr[1][j - vec[i]];
			}
		}
	}

	N % 2 == 0 ? cout << arr[0][k] << endl : cout << arr[1][k] << endl;
	system("pause");
	return 0;
}