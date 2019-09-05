#include<iostream>
#include<vector>
using namespace std;
int M, N;
int arr[51][51] = { 0, };
bool check[51][51] = { false, };
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
void dfs(int x, int y) {
	check[y][x] = true;
	for (int i = 0; i < 4; i++) {
		if (x + dx[i] < 0 || y + dy[i] < 0 || x + dx[i] >= M || y + dy[i] >= N)
			continue;
		if (check[y + dy[i]][x + dx[i]] == false && arr[y + dy[i]][x + dx[i]] == 1) {
			dfs(x + dx[i], y + dy[i]);
		}
	}
}

int main(void) {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int K, X, Y, result = 0;	//가로 세로 배추개수 배추위치X, Y
		cin >> M >> N >> K;
		for (int j = 0; j < K; j++) {
			cin >> X >> Y;
			arr[Y][X] = 1;
		}
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++)
				if (check[j][k] == false && arr[j][k] == 1) {
					dfs(k, j);
					result++;
				}
		}
		cout << result << endl;

		for (int j = 0; j <= N; j++)
			for (int k = 0; k <= M; k++) {
				arr[j][k] = 0;
				check[j][k] = false;
			}
	}
	system("pause");
	return 0;
}