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
void dfs(int start_y, int stat_x, int next_y, int next_x) {
/*
	만약 way[next_y][next_x]의 값이 -1이라면 한번도 안 다녀온 것
	계산해서 집어넣기
	한번씩 돌면서 way에 -1값이 없을때까지 만들어주기
*/
}

void start() {
	for (int i = 1; i < 501; i++)
		for (int j = 1; j < 501; j++)
			way[i][j] = -1;
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	start();
	cin >> N;
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
			dfs(i, j, 0, 0);
		}
	}
	cout << maximum << endl;
	system("pause");
	return 0;
}