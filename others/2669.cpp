#include<iostream>
#include<vector>
using namespace std;
bool check[101][101] = { false, };
int arr[101][101] = { 0, };
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int area = 0;
void dfs(int x, int y) {
	check[y][x] = true;
	area++;
	for (int i = 0; i < 4; i++) {
		if (x + dx[i] < 0 || x + dx[i] > 100 || y + dy[i] < 0 || y + dy[i] >100)
			continue;
		if (check[y + dy[i]][x + dx[i]] == false && arr[y+dy[i]][x+dx[i]] ==1) {
			dfs(x + dx[i], y + dy[i]);
		}
	}
}

int main(void) {
	int x1, y1, x2, y2;
	for (int i = 0; i < 4; i++) {
		cin >> x1 >> y1 >> x2 >> y2;
		for (int j = y1; j < y2; j++) {
			for (int k = x1; k < x2; k++) {
				arr[j][k] = 1;
			}
		}
	}
	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			if (check[i][j] == false && arr[i][j]==1) {
				dfs(j, i);
			}
		}
	}
	cout << area << endl;

	system("pause");
	return 0;
}