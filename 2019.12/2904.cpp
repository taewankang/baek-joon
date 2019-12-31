#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<pair<int, int>> virus_location;
int empty_num = 0, virus_num = 0;
int N, M, n, result = 987654321;
vector<bool> selected;
int arr_x[4] = { 1, -1, 0, 0 };
int arr_y[4] = { 0, 0, 1, -1 };
int all_case = 0, fail_case = 0, activated = 0;

void bfs(vector<vector<int>> vec) {
	queue<pair<int, int>> q;
	int counting = 0;
	int minimum = 0;
	for (int i = 0; i < selected.size(); i++) {
		if (selected[i] == true) {
			q.push({ virus_location[i + 1].first, virus_location[i + 1].second });
			vec[virus_location[i + 1].first][virus_location[i + 1].second] = 1;
		}
	}

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int next_y = y + arr_y[i];
			int next_x = x + arr_x[i];
			if (empty_num == counting) {
				if (result > minimum)
					result = minimum;
				return;
			}

			if (next_x > 0 && next_x <= N && next_y > 0 && next_y <= N && (vec[next_y][next_x] == 0 || vec[next_y][next_x] == -2)) {
				if (vec[next_y][next_x] == -2)
					counting--;
				q.push({ next_y, next_x });
				vec[next_y][next_x] = vec[y][x] + 1;
				if (vec[next_y][next_x] > minimum)
					minimum = vec[next_y][next_x];
				counting++;
			}
		}
		if (empty_num == counting) {
			if (result > minimum)
				result = minimum;
		}
	}
	if (empty_num != counting)
		fail_case++;

}

void virus_select(vector<vector<int>>& vec, int idx, int cnt) {
	if (M == cnt) {
		bfs(vec);
		all_case++;
		return;
	}
	for (int i = idx; i < virus_num; i++) {
		if (selected[i] == true)	continue;
		selected[i] = true;
		virus_select(vec, i, cnt + 1);
		selected[i] = false;
	}
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> N >> M;
	vector<vector<int>> vec(N + 1);
	virus_location.push_back({ 0, 0 });
	for (int i = 1; i <= N; i++) {
		vec[i].push_back(0);
		for (int j = 1; j <= N; j++) {
			cin >> n;
			if (n == 2) {
				virus_num++;
				virus_location.push_back({ i, j });
				selected.push_back(false);
				vec[i].push_back(-2);
				continue;
			}
			else if (n == 1) {
				vec[i].push_back(-1);
				continue;
			}
			if (n == 0)
				empty_num++;
			vec[i].push_back(n);
		}
	}
	if (empty_num == 0) {
		cout << 0 << "\n";
		return 0;
	}

	virus_select(vec, 0, 0);

	if (all_case != fail_case)
		cout << result - 1 << endl;
	else
		cout << "-1\n";
	system("pause");
	return 0;
}