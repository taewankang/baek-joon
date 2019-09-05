#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };	
bool check[101][101] = { false, };

bool rain_height(vector<vector<int>> &vec, int height) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (vec[i][j] <= height) {
				check[i][j] = true;
			}
			else {
				check[i][j] = false;
			}
		}
	}
	return check;
}

void dfs(vector<vector<int>> &vec, int height, int x, int y) {
	check[y][x] = true;
	for (int i = 0; i < 4; i++) {
		if (x + dx[i] < 0 || y + dy[i] < 0 || x + dx[i] >= N || y + dy[i] >= N)
			continue;
		if (check[y + dy[i]][x + dx[i]] == false) {
			dfs(vec, height, x + dx[i], y + dy[i]);
		}
	}
}

int main(void) {
	int n, max_num=0;
	cin >> N;
	int max_domain = 0;
	vector<vector<int>> vec(N);
	vector<int> result;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> n;
			if (max_num < n)
				max_num = n;
			vec[i].push_back(n);
		}
	}
	for (int k = 0; k <= max_num; k++) {
		max_domain = 0;
		rain_height(vec, k);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (check[i][j] == false) {
					dfs(vec, k, j, i);
					max_domain++;
				}
			}
		}
		result.push_back(max_domain);
	}
	sort(result.begin(), result.end());
	cout << result[result.size() - 1] << endl;
	system("pause");
	return 0;
}