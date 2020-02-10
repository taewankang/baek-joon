#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<math.h>
using namespace std;
int N, M, D;
int arr[16][16] = { 0, };
bool check[16] = { 0, };
struct Dir {
	int y, x;
};

Dir dir[3] = { {0, -1}, {-1, 0}, {0, 1} };
int maximum;
pair<int, pair<int, int>> distance(int y, int x, int temp[16][16]) {
	bool visit[16][16] = { false, };
	visit[y][x] = true;
	queue<pair<int, pair<int, int>>> q;
	vector<pair<int, pair<int, int>>> v;
	if (temp[y][x] == 1)
		return { 1, {x, y} };
	v.push_back({ 1, {x, y} });
	q.push({ 1, { x, y } });
	while (!q.empty()) {
		int new_x = q.front().second.first;
		int new_y = q.front().second.second;
		int distance = q.front().first;
		q.pop();
		if (distance >= D)
			continue;
		for (int i = 0; i < 3; i++) {
			int next_y = new_y + dir[i].y;
			int next_x = new_x + dir[i].x;
			if (next_y > 0 && next_y <= y && next_x > 0 && next_x <= M && visit[next_y][next_x] == false) {
				visit[next_y][next_x] = true;
				q.push({ distance + 1, {next_x, next_y} });
				v.push_back({ distance + 1, {next_x, next_y} });
			}
		}
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		if (temp[v[i].second.second][v[i].second.first] == 1)
			return v[i];
	}
	return { 0, {0, 0} };
}

void calculate(vector<int> vec) {
	int temp[16][16] = { 0, };
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			temp[i][j] = arr[i][j];
		}
	}
	pair<int, pair<int, int>> p1, p2, p3;
	int result = 0;
	for (int i = N; i > 0; i--) {
		p1 = distance(i, vec[0], temp);
		p2 = distance(i, vec[1], temp);
		p3 = distance(i, vec[2], temp);
		if (temp[p1.second.second][p1.second.first] == 1) {
			temp[p1.second.second][p1.second.first] = 0;
			result++;
		}
		if (temp[p2.second.second][p2.second.first] == 1) {
			temp[p2.second.second][p2.second.first] = 0;
			result++;
		}
		if (temp[p3.second.second][p3.second.first] == 1) {
			temp[p3.second.second][p3.second.first] = 0;
			result++;
		}
	}
	maximum < result ? maximum = result : NULL;

}

void permu(int idx, int cnt) {
	if (cnt == 3) {
		vector<int> v;
		for (int i = 1; i <= M; i++)
			if (check[i] == true)
				v.push_back(i);
		calculate(v);

		return;
	}

	for (int i = idx; i <= M; i++) {
		if (check[i])	continue;
		check[i] = true;
		permu(i, cnt + 1);
		check[i] = false;
	}
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> N >> M >> D;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> arr[i][j];
		}
	}

	permu(1, 0);
	cout << maximum << endl;

	system("pause");
	return 0;
}

