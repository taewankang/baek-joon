#include<iostream>
using namespace std;
char arr1[101][101];
char arr2[101][101];
bool visit1[101][101] = { 0, };
bool visit2[101][101] = { 0, };
int count1 = 0, count2 = 0, N;

void dfs(int x, int y) {
	visit1[x][y] = true;
	if (visit1[x][y + 1] == false && (arr1[x][y] == arr1[x][y + 1])) {
		dfs(x, y + 1);
	}
	if (y > 0 && visit1[x][y - 1] == false && (arr1[x][y] == arr1[x][y - 1])) {
		dfs(x, y - 1);
	}
	if (x > 0 && visit1[x - 1][y] == false && (arr1[x][y] == arr1[x - 1][y])) {
		dfs(x - 1, y);
	}
	if (visit1[x + 1][y] == false && arr1[x][y] == arr1[x + 1][y]) {
		dfs(x + 1, y);
	}
}

void dfs2(int x, int y) {
	visit2[x][y] = true;
	if (visit2[x][y + 1] == false && (arr2[x][y] == arr2[x][y + 1])) {
		dfs2(x, y + 1);
	}
	if (y > 0 && visit2[x][y - 1] == false && (arr2[x][y] == arr2[x][y - 1])) {
		dfs2(x, y - 1);
	}
	if (x > 0 && visit2[x - 1][y] == false && (arr2[x][y] == arr2[x - 1][y])) {
		dfs2(x - 1, y);
	}
	if (visit2[x + 1][y] == false && arr2[x][y] == arr2[x + 1][y]) {
		dfs2(x + 1, y);
	}
}

int main(void) {
	char color;
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> color;
			arr1[i][j] = color;
			if (color == 'R')
				color = 'G';
			arr2[i][j] = color;
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (visit1[i][j] == false) {
				count1++;
				dfs(i, j);
			}
			if (visit2[i][j] == false) {
				count2++;
				dfs2(i, j);
			}
		}
	}
	cout << count1 << " " << count2 << endl;
	system("pause");
	return 0;
}