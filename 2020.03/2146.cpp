#include <iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<string>
#include<string.h>
using namespace std;
int N;
int map[101][101] = { 0, };
bool check[101][101] = { false, };
struct Dir {
	int y, x;
};
Dir dir[4] = { {1, 0}, {-1, 0},  {0, 1}, {0, -1} };
int result = 123456789;
void divide(int y, int x, int cnt) {		//섬마다 번호를 붙여준다.
	queue<pair<int, int>> q;
	q.push({ y, x });
	map[y][x] = cnt;
	check[y][x] = true;
	while (!q.empty()) {
		int new_y = q.front().first;
		int new_x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int next_y = new_y + dir[i].y;
			int next_x = new_x + dir[i].x;
			if (next_y > 0 && next_y <= N && next_x > 0 && next_x <= N && map[next_y][next_x] == 1) {
				check[next_y][next_x] = true;
				map[next_y][next_x] = cnt;
				q.push({ next_y, next_x });
			}
		}
	}
}

bool surround(int y, int x) {		//다리가 놓을 수 있는 위치라면(섬의 테두리 부분이라면)
	for (int i = 0; i < 4; i++) {
		if (!map[y + dir[i].y][x + dir[i].x])
			return true;
	}
	return false;
}

void dfs(int y, int x) {		//bfs방식을 이용해서 다른 섬으로 가는 다리의 수를 찾아준다.
	queue<pair<pair<int, int>, int>> q;		//현재 좌표의 y, x, 몇번째 다리인지
	q.push({ {y, x}, 0 });
	int num = map[y][x];
	while (!q.empty()) {
		int new_y = q.front().first.first;
		int new_x = q.front().first.second;
		int cnt = q.front().second;
		q.pop();
		if (map[new_y][new_x] != num && map[new_y][new_x] != 0) {
			result > cnt ? result = cnt : NULL;
			return;
		}
		for (int i = 0; i < 4; i++) {
			int next_y = new_y + dir[i].y;
			int next_x = new_x + dir[i].x;
			if (next_y > 0 && next_y <= N && next_x > 0 && next_x <= N && map[next_y][next_x] != num && !check[next_y][next_x]) {
				check[next_y][next_x] = true;
				q.push({ { next_y, next_x }, cnt + 1 });
			}
		}
	}
}

void reset() {			//check배열의 초기화를 진행한다.
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++)
			check[i][j] = false;
	}
}

int main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
		}
	}

	int cnt = 2;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (map[i][j] == 1)
				divide(i, j, cnt++);
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (map[i][j] && surround(i, j)) {		//다리를 놓을 수 있는 위치라면
				dfs(i, j);
				reset();
			}
		}
	}

	cout << result - 1 << endl;
	system("pause");
	return 0;
}
