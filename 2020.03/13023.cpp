#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N, M, a, b;
vector<vector<int>> vec(2001);
int check[2001] = { false, };
bool finish = false;
void dfs(int start, int depth) {
	if (depth == 4) {
		finish = true;
		return;
	}
	for (int i = 0; i < vec[start].size(); i++) {
		if (!check[vec[start][i]]) {
			check[vec[start][i]] = true;
			dfs(vec[start][i], depth + 1);
			check[vec[start][i]] = false;
		}
	}
}

int main(void) {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	bool result = false;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}

	for (int i = 0; i < N; i++) {
		check[i] = true;
		dfs(i, 0);
		if (finish)
			break;
		for (int i = 0; i < N; i++)
			check[i] = false;
	}
	finish == true ? cout << "1\n" : cout << "0\n";
	system("pause");
	return 0;
}