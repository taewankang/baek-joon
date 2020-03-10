#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int T, N, M, K;
int map[51][51] = { 0, };
struct Dir {
	int y, x;
};
Dir dir[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
void reset() {
	for (int i = 0; i < 51; i++) {
		for (int j = 0; j < 51; j++) {
			map[i][j] = 0;
		}
	}
}

void bfs(int y, int x) {
	queue<pair<int, int>> q;
	q.push({ y, x });
	while (!q.empty()) {
		int new_y = q.front().first;
		int new_x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int next_y = new_y + dir[i].y;
			int next_x = new_x + dir[i].x;
			if (next_y >= 0 && next_y < N && next_x >= 0 && next_x < M && map[next_y][next_x] == 1) {
				q.push({ next_y, next_x });
				map[next_y][next_x] = 0;
			}
		}
	}
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> T;
	int x, y;
	for (int i = 0; i < T; i++) {
		cin >> M >> N >> K;
		int result = 0;
		for (int i = 0; i < K; i++) {
			cin >> x >> y;
			map[y][x] = 1;
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j] == 1) {
					bfs(i, j);
					result++;
				}
			}
		}
		cout << result << endl;
		reset();
	}

	system("pause");
	return 0;
}