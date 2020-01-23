#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int maximum = 0;
int N, M, n;
int arr_x[4] = { 1, -1, 0, 0 };
int arr_y[4] = { 0, 0, 1, -1 };
vector<vector<int>> vec(501);

void dfs(int y, int x, int cnt, int sum, bool(*check)[501]) {
	if (cnt == 3) {
		maximum < sum ? maximum = sum : NULL;
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (y + arr_y[i] > 0 && y + arr_y[i] <= N && x + arr_x[i] > 0 && x + arr_x[i] <= M && check[y + arr_y[i]][x + arr_x[i]] == false) {
			check[y + arr_y[i]][x + arr_x[i]] = true;
			dfs(y + arr_y[i], x + arr_x[i], cnt + 1, sum + vec[y + arr_y[i]][x + arr_x[i]], check);
			check[y + arr_y[i]][x + arr_x[i]] = false;
		}
	}
}

void compare(int y, int x) {
	int sum = 0;
	if (y > 0 && y < N && x > 1 && x < M) {
		sum = vec[y + 1][x];
		sum += vec[y][x - 1];
		sum += vec[y][x];
		sum += vec[y][x + 1];
		maximum = max(maximum, sum);
	}
	if (y > 1 && y < N && x > 0 && x < M) {
		sum = vec[y][x + 1];
		sum += vec[y + 1][x];
		sum += vec[y - 1][x];
		sum += vec[y][x];
		maximum = max(maximum, sum);
	}
	if (y > 1 && y < N && x > 1 && x <= M) {
		sum = vec[y + 1][x];
		sum += vec[y - 1][x];
		sum += vec[y][x - 1];
		sum += vec[y][x];
		maximum = max(maximum, sum);
	}
	if (y > 1 && y <= N && x > 1 && x < M) {
		sum = vec[y][x + 1];
		sum += vec[y - 1][x];
		sum += vec[y][x - 1];
		sum += vec[y][x];
		maximum = max(maximum, sum);
	}
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> N >> M;
	bool check[501][501] = { false, };

	for (int i = 1; i <= N; i++) {
		vec[i].push_back(0);
		for (int j = 1; j <= M; j++) {
			cin >> n;
			vec[i].push_back(n);
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			check[i][j] = true;
			dfs(i, j, 0, vec[i][j], check);
			check[i][j] = false;
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			compare(i, j);
		}
	}
	cout << maximum << endl;
	system("pause");
	return 0;
}