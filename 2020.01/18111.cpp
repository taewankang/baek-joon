#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int N, M, B, highest = 0, lowest = 257;
long long time = 99999999999, height = 0;
int arr[501][501] = { 0, };
int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> N >> M >> B;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> arr[i][j];
			highest < arr[i][j] ? highest = arr[i][j] : NULL;
			lowest > arr[i][j] ? lowest = arr[i][j] : NULL;
		}
	}

	for (int h = highest; h >= lowest; h--) {
		int t = 0;
		bool success = true;
		int temp = B;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				if (arr[i][j] > h) {		//블록을 제거
					t += (arr[i][j] - h) * 2;
					temp += (arr[i][j] - h);
				}
				else if (arr[i][j] < h) {		//블록을 넣기
					t += (h - arr[i][j]);
					temp -= (h - arr[i][j]);
				}
			}
		}
		if (temp >= 0 && time > t) {
			time = t;
			height = h;
		}
	}

	cout << time << " " << height << endl;
	system("pause");
	return 0;
}