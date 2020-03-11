#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int w, h, n;
struct Dir {
	int y, x;
};

Dir dir[8] = { {1, 0}, {0, 1}, {0, -1}, {-1, 0}, {1, -1}, {1, 1}, {-1, 1}, {-1, -1} };
vector<vector<int>> bfs(int y, int x, vector<vector<int>> vec) {
	queue<pair<int, int>> q;
	q.push({ y, x });
	while (!q.empty()) {
		int new_y = q.front().first;
		int new_x = q.front().second;
		q.pop();
		for (int i = 0; i < 8; i++) {
			int next_y = new_y + dir[i].y;
			int next_x = new_x + dir[i].x;
			if (next_y > 0 && next_y <= h && next_x > 0 && next_x <= w && vec[next_y][next_x]) {
				vec[next_y][next_x] = 0;
				q.push({ next_y, next_x });
			}
		}
	}
	return vec;
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	while (1) {
		cin >> w >> h;		//가로 세로
		if (w == 0 && h == 0)
			break;
		int cnt = 0;
		vector<vector<int>> vec(h + 1);
		for (int i = 1; i <= h; i++) {
			vec[i].push_back(0);
			for (int j = 1; j <= w; j++) {
				cin >> n;
				vec[i].push_back(n);
			}
		}
		for (int i = 1; i <= h; i++) {
			for (int j = 1; j <= w; j++) {
				if (vec[i][j]) {
					vec = bfs(i, j, vec);
					cnt++;
				}
			}
		}
		cout << cnt << endl;
		cout << endl;
	}
	system("pause");
	return 0;
}