#include<iostream>
#include<vector>
using namespace std;
int result = 0, R = 0, C = 0;
vector<vector<char>> vec(21);
vector<bool> alpha(27, false);
void dfs(int x, int y, int dis) {
	alpha[vec[y][x] - 'A'] = true;
	if (dis > result) {
		result = dis;
	}
	if (x + 1 < C && alpha[vec[y][x + 1] - 'A'] == false) {
		dfs(x + 1, y, dis + 1);
	}
	if (x > 0 && alpha[vec[y][x - 1] - 'A'] == false) {
		dfs(x - 1, y, dis + 1);
	}
	if (y > 0 && alpha[vec[y - 1][x] - 'A'] == false) {
		dfs(x, y - 1, dis + 1);
	}
	if (y + 1 < R && alpha[vec[y + 1][x] - 'A'] == false) {
		dfs(x, y + 1, dis + 1);
	}
	alpha[vec[y][x] - 'A'] = false;
	return;
}

int main(void) {
	char c;
	cin >> R >> C;
	vector<bool> alpha(27, false);
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> c;
			vec[i].push_back(c);
		}
	}
	dfs(0, 0, 1);
	cout << result << endl;
	system("pause");
	return 0;
}