#include<iostream>
#include<vector>
#include<queue>
#include<math.h>
using namespace std;
int N, L, R, result, cnt, cnt2;
vector<vector<int>> vec(51);
int arr_x[4] = { 1, -1, 0, 0 };
int arr_y[4] = { 0, 0, 1, -1 };
bool visit[51][51] = { 0, };
bool visited[51][51] = { 0, };
vector<int> sum;

vector<pair<int, int>> bfs(int y, int x) {
	vector<pair<int, int>> change;
	int total = vec[y][x];
	queue<pair<int, int>> q;
	q.push({ y, x });
	change.push_back({ y, x });
	visit[y][x] = true;
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			if (y + arr_y[i] > 0 && y + arr_y[i] <= N && x + arr_x[i] > 0 && x + arr_x[i] <= N && visit[y + arr_y[i]][x + arr_x[i]] == false) {
				int diff = abs(vec[y][x] - vec[y + arr_y[i]][x + arr_x[i]]);
				if (diff >= L && diff <= R) {
					q.push({ y + arr_y[i], x + arr_x[i] });
					visit[y + arr_y[i]][x + arr_x[i]] = true;
					total += vec[y + arr_y[i]][x + arr_x[i]];
					change.push_back({ y + arr_y[i], x + arr_x[i] });
				}
			}
		}
	}
	sum.push_back(total);
	return change;
}

void start() {
	result++;
	cnt = 0;
	vector<vector<pair<int, int>>> change(2501);
	sum.clear();
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++)
			visit[i][j] = false;
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (visit[i][j] == false) {
				change[cnt] = (bfs(i, j));
				cnt++;
			}
		}
	}
	for (int i = 0; i < cnt; i++) {
		int avg = sum[i] / change[i].size();
		for (int j = 0; j < change[i].size(); j++) {
			vec[change[i][j].first][change[i][j].second] = avg;
		}
	}
}

bool check_bfs(int y, int x) {
	for (int i = 0; i < 4; i++) {
		if (y + arr_y[i] > 0 && y + arr_y[i] <= N && x + arr_x[i] > 0 && x + arr_x[i] <= N) {
			int diff = abs(vec[y][x] - vec[y + arr_y[i]][x + arr_x[i]]);
			if (diff >= L && diff <= R)
				return false;
		}
	}
	return true;
}

bool checking() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (check_bfs(i, j) == false) {
				return false;
			}
		}
	}
	return true;
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> N >> L >> R;
	int n;
	for (int i = 1; i <= N; i++) {
		vec[i].push_back(0);
		for (int j = 1; j <= N; j++) {
			cin >> n;
			vec[i].push_back(n);
		}
	}

	while (1) {
		if (checking()) {		//³¡
			cout << result << endl;
			break;
		}
		start();
	}

	system("pause");
	return 0;
}
