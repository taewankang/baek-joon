#include <iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<string>
#include<string.h>
using namespace std;
bool check[2][1001][1001] = { false, };
int map[1001][1001] = { 0, };
int N, M;
struct Dir { int y, x; };
Dir dir[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

void bfs() {
	queue<pair<pair<int, int>, pair<int, int>>> q;
	q.push({ { 1, 1 },{0, 1} });	//y, x, 내가 벽을 뚫었나? 몇번째인가?
	check[0][1][1] = true;
	check[1][1][1] = true;
	int result = 123456789;
	while (!q.empty()) {
		int y = q.front().first.first;
		int x = q.front().first.second;
		int visit = q.front().second.first;
		int cnt = q.front().second.second;
		q.pop();
		if (y == N && x == M)
			result > cnt ? result = cnt : NULL;
		for (int i = 0; i < 4; i++) {
			int next_y = y + dir[i].y;
			int next_x = x + dir[i].x;
			if (next_y > 0 && next_y <= N && next_x > 0 && next_x <= M) {
				if (map[next_y][next_x] == 0 && visit == 0 && !check[0][next_y][next_x]) {		//다음으로 갈 곳이 벽이 아니고 아직 벽을 안 뚫었다면
					q.push({ { next_y, next_x }, {0, cnt + 1} });
					check[0][next_y][next_x] = true;
				}
				else if (map[next_y][next_x] == 0 && visit == 1 && !check[1][next_y][next_x]) {	//다음으로 갈 곳이 벽이 아니고 벽을 뚫은 적이 있다면
					q.push({ {next_y, next_x}, {1, cnt + 1} });
					check[1][next_y][next_x] = true;
				}
				else if (map[next_y][next_x] == 1 && visit == 0 && !check[0][next_y][next_x]) {	//다음으로 갈 곳이 벽이고 벽을 뚫은 적이 없다면
					q.push({ {next_y, next_x}, {1, cnt + 1} });
					check[1][next_y][next_x] = true;
				}
			}
		}
	}
	result == 123456789 ? result = -1 : NULL;
	cout << result << endl;
}

//벽을 부쉈고 다음이 벽이 아니라면 --> 다음으로 넘어갈 수 있다.
//벽을 부수지 않았고 다음이 벽이 아니라면 --> 그냥 갈수있다.
//벽을 부수지 않았고 다음이 벽이라면 --> 갈수있다..

int main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < str.length(); j++) {
			map[i][j + 1] = str[j] - '0';
		}
	}
	bfs();

	system("pause");
	return 0;
}
