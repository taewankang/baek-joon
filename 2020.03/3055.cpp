#include<iostream>
#include<string>
#include<string.h>
#include<queue>
using namespace std;
int N, M, dest_y, dest_x;
char map[51][51];
bool check[51][51] = { 0, };
bool animal_check[51][51] = { 0, };
queue<pair<pair<int, int>, int>> water;
queue<pair<pair<int, int>, int>> animal;
int depth = 0;
struct Dir { int y, x; };
Dir dir[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

void water_move() {
	while (!water.empty()) {
		int y = water.front().first.first;
		int x = water.front().first.second;
		int dep = water.front().second;
		if (dep != depth)
			return;
		water.pop();
		for (int i = 0; i < 4; i++) {
			int nextY = y + dir[i].y;
			int nextX = x + dir[i].x;
			if (nextY > 0 && nextY <= N && nextX > 0 && nextX <= M) {
				if (!check[nextY][nextX] && map[nextY][nextX] != 'D' && map[nextY][nextX] != 'X') {
					check[nextY][nextX] = true;
					water.push({ {nextY, nextX}, dep + 1 });
				}
			}
		}
	}
}

int animal_move() {
	while (!animal.empty()) {
		int y = animal.front().first.first;
		int x = animal.front().first.second;
		int dep = animal.front().second;
		if (y == dest_y && x == dest_x)
			return dep;
		if (dep != depth)
			return 0;
		animal.pop();
		for (int i = 0; i < 4; i++) {
			int nextY = y + dir[i].y;
			int nextX = x + dir[i].x;
			if (nextY > 0 && nextY <= N && nextX > 0 && nextX <= M) {
				if (!check[nextY][nextX] && map[nextY][nextX] != 'X' && !animal_check[nextY][nextX]) {
					animal_check[nextY][nextX] = true;
					animal.push({ {nextY, nextX}, dep + 1 });
				}
			}
		}
	}
	return 0;
}

int bfs() {
	while (!animal.empty()) {
		water_move();		//1분마다 물의 움직임을 나타내는 함수
		int res = animal_move();		//1분마다 동물들이 이동할 수 있는 위치를 나타내는 함수
		if (res) return res;			//목적지에 도착하면 무한루프 탈출
		depth++;			//1분마다 일어날 수 있도록 함
	}
	return 0;
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> N >> M;
	string str;
	for (int i = 1; i <= N; i++) {
		cin >> str;
		for (int j = 0; j < M; j++) {
			if (str[j] == '*') {
				water.push({ { i, j + 1 }, 0 });
				check[i][j + 1] = true;
			}
			else if (str[j] == 'D') {
				dest_y = i;
				dest_x = j + 1;
			}
			else if (str[j] == 'S') {
				animal_check[i][j + 1] = true;
				animal.push({ {i, j + 1}, 0 });
			}
			else if (str[j] == 'X') {
				check[i][j + 1] = true;
				animal_check[i][j + 1] = true;
			}
			map[i][j + 1] = str[j];
		}
	}

	int result = bfs();
	result == 0 ? cout << "KAKTUS\n" : cout << result << endl;
	system("pause");
	return 0;
}