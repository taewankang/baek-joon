#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N, M;
vector<vector<int>> vec(1001);
bool check[1001] = { false, };
void dfs(int start) {
	check[start] = true;
	for (int i = 0; i < vec[start].size(); i++) {
		if (!check[vec[start][i]]) {
			dfs(vec[start][i]);
		}
	}
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> N >> M;
	int a, b, result = 0;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}

	for (int i = 1; i <= N; i++)
		sort(vec[i].begin(), vec[i].end());

	for (int i = 1; i <= N; i++) {
		if (!check[i]) {
			dfs(i);
			result++;
		}
	}
	cout << result << endl;
	system("pause");
	return 0;
}