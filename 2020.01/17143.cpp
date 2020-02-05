#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int R, C, M;
struct Shark {
	int s, d, z;
};
struct Dir {
	int y, x;
};
vector<vector<Shark>> map(101), vec(101);
Shark shark[10001];
Dir dir[5] = { {0, 0}, {0, -1}, {0, 1}, {1, 0}, {-1, 0} };	//1, 2, 3, 4
int sum = 0;
void hunt(int idx) {
	for (int i = 1; i <= R; i++) {
		if (map[i][idx].d != 0) {
			sum += map[i][idx].z;
			map[i][idx].s = 0;
			map[i][idx].d = 0;
			map[i][idx].z = 0;
			break;
		}
	}
}

void compare(int y, int x, int new_y, int new_x, int new_d) {	//움직이기 전,   움직인 후
	if (map[y][x].z >= vec[new_y][new_x].z) {		//기존의 것보다 크다면
		vec[new_y][new_x].d = new_d;
		vec[new_y][new_x].s = map[y][x].s;
		vec[new_y][new_x].z = map[y][x].z;
	}
}

vector<int> one_two_move(int s, int d, int next_y) {
	vector<int> v(2);
	while (1) {
		if (s-- == 0) break;
		if (d == 1) {
			if (--next_y < 1) {
				d = 2;
				next_y += 2;
			}
		}
		else if (d == 2) {
			if (++next_y > R) {
				d = 1;
				next_y -= 2;
			}
		}
	}
	v[0] = d;
	v[1] = next_y;
	return v;
}

vector<int> three_four_move(int s, int d, int next_x) {
	vector<int> v(2);
	while (1) {
		if (s-- == 0) break;
		if (d == 3) {
			if (++next_x > C) {
				d = 4;
				next_x -= 2;
			}
		}
		else if (d == 4) {
			if (--next_x < 1) {
				d = 3;
				next_x += 2;
			}
		}
	}
	v[0] = d;
	v[1] = next_x;
	return v;
}

void move(int y, int x, int d, int s) {
	int next_x = x, next_y = y;
	if (d == 1 || d == 2) {
		s %= 2 * (R - 1);
		vector<int> v = one_two_move(s, d, next_y);
		d = v[0];
		next_y = v[1];
	}
	else if (d == 3 || d == 4) {
		s %= 2 * (C - 1);
		vector<int> v = three_four_move(s, d, next_x);
		d = v[0];
		next_x = v[1];
	}
	compare(y, x, next_y, next_x, d);
}

void start() {
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++)
			vec[i][j] = { 0, 0, 0 };
	}

	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if (map[i][j].d != 0) {
				move(i, j, map[i][j].d, map[i][j].s);
			}
		}
	}

	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			map[i][j].d = vec[i][j].d;
			map[i][j].s = vec[i][j].s;
			map[i][j].z = vec[i][j].z;
		}
	}
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> R >> C >> M;
	int n;
	for (int i = 1; i <= R; i++) {
		map[i].push_back({ 0, 0, 0 });
		vec[i].push_back({ 0, 0, 0 });
		for (int j = 1; j <= C; j++) {
			map[i].push_back({ 0, 0, 0 });
			vec[i].push_back({ 0, 0, 0 });
		}
	}
	int r, c, s, d, z;
	for (int i = 0; i < M; i++) {
		cin >> r >> c >> s >> d >> z;
		map[r][c] = { s, d, z };
	}

	for (int i = 1; i <= C; i++) {
		hunt(i);
		start();
	}

	cout << sum << endl;

	system("pause");
	return 0;
}

