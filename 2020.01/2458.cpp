/*
플로이드-와샬 알고리즘을 이용해서 노드간의 연결점을 찾고 모든 노드와 연결된 노드의 개수를 찾으면 되는 문제
*/

#include<iostream>
using namespace std;
int arr[501][501] = { 0, };
int check[501] = { 0, };
int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int N, M, a, b;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		arr[a][b] = 1;
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= N; k++) {
				if (j == k)	continue;
				if (arr[j][i] == 0 || arr[i][k] == 0)	continue;
				arr[j][k] = 1;
			}
		}
	}

	int result = 0;
	for (int i = 1; i < N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == j)	continue;
			if (arr[i][j] == 0 && arr[j][i] == 0)
				break;
			if (j == N) {
				result++;
			}
		}
	}
	for (int i = 1; i < N; i++) {
		if (arr[N][i] == 0 && arr[i][N] == 0)
			break;
		if (i == N - 1)
			result++;
	}
	cout << result << endl;
	system("pause");
	return 0;
}