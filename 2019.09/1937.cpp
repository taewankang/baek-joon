#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int N;
int x_arr[4] = { 1, -1, 0, 0 };
int y_arr[4] = { 0, 0, 1, -1 };
int maximum;


vector<vector<int>> vec(501);
int way[501][501];
int startX, startY;
void show() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++)
			cout << way[i][j] << " ";
		cout << endl;
	}
}
void dfs(int start_y, int start_x, int next_y, int next_x, int depth) {
	cout << endl;
	show();
	bool no_way = false;
	for (int i = 0; i < 4; i++) {
		next_x = x_arr[i] + start_x;
		next_y = y_arr[i] + start_y;
		cout << "before start_x: " << start_x << " start_y: " << start_y << " next_x: " << next_x << " next_y " << next_y << endl;
		if (next_x > 0 && next_x <= N && next_y > 0 && next_y <= N && vec[start_y][start_x] < vec[next_y][next_x]) {
			cout << "start_x: " << start_x << " start_y: " << start_y << " next_x: " << next_x << " next_y " << next_y << endl;
			no_way = true;
			if (way[next_y][next_x] == -1) {
				dfs(next_y, next_x, 0, 0, depth + 1);
			}
			else {
				if (way[start_y][start_x] < way[next_y][next_x]) {
					way[start_y][start_x] = way[next_y][next_x] + 1;
				}
			}
		}
	}
	if (no_way == false)
		way[start_y][start_x] = 1;
}

void start() {
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			way[i][j] = -1;
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> N;
	start();
	int n;
	for (int i = 1; i <= N; i++) {
		vec[i].push_back(0);
		for (int j = 1; j <= N; j++) {
			cin >> n;
			vec[i].push_back(n);
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			startX = j;	startY = i;
			if (way[startY][startX] == -1)
				way[startY][startX] = 1;
			dfs(i, j, 0, 0, 1);
		}
	}
	cout << maximum << endl;
	system("pause");
	return 0;
}