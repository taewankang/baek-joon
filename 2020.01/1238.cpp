#include<iostream>
#include<algorithm>
using namespace std;
int arr[1001][1001] = { 0, };
int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int N, M, X, from, to, cost, result = 0;
	cin >> N >> M >> X;
	for (int i = 0; i < M; i++) {
		cin >> from >> to >> cost;
		arr[from][to] = cost;
	}

	for (int i = 1; i <= N; i++) {			//다른 노드로 가는 최단 거리를 구하는 반복문
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= N; k++) {
				if (j == k)	continue;
				if (arr[j][i] == 0 || arr[i][k] == 0)	continue;
				if (arr[j][k] == 0) {
					arr[j][k] = arr[j][i] + arr[i][k];
				}
				else {
					arr[j][k] = min(arr[j][k], arr[j][i] + arr[i][k]);
				}
			}
		}
	}

	for (int i = 1; i <= N; i++)			//결과 구하기
		result < arr[i][X] + arr[X][i] ? result = arr[i][X] + arr[X][i] : NULL;
	cout << result << endl;
	system("pause");
	return 0;
}