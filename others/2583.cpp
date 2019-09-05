#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool visit[101][101] = { false, };
int graph[101][101];
int result = 0;
vector<int> vec;
int area = 1;
void dfs(int x, int y) {
	visit[x][y] = true;
	if (x > 0 && visit[x - 1][y] == false && graph[x][y] == graph[x - 1][y]) {
		area++;
		dfs(x - 1, y);
	}
	if (y > 0 && visit[x][y - 1] == false && graph[x][y] == graph[x][y - 1]) {
		area++;
		dfs(x, y - 1);
	}
	if (visit[x][y + 1] == false && (graph[x][y] == graph[x][y + 1])) {
		area++;
		dfs(x, y + 1);
	}
	if (visit[x + 1][y] == false && graph[x][y] == graph[x + 1][y]) {
		area++;
		dfs(x + 1, y);
	}
}

int main(void) {
	int N, M, K;
	for (int i = 0; i < 101; i++)
		for (int j = 0; j < 101; j++)
			graph[i][j] = 2;
	cin >> N >> M >> K;
	int x1, x2, y1, y2;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			graph[i][j] = 0;
	for (int i = 0; i < K; i++) {
		cin >> x1 >> y1 >> x2 >> y2;
		for (int s = y1; s < y2; s++) {
			for (int j = x1; j < x2; j++) {
				graph[s][j] = 1;
				visit[s][j] = true;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (visit[i][j] == false) {
				result++;
				area = 1;
				dfs(i, j);
				vec.push_back(area);
			}
		}
	}
	sort(vec.begin(), vec.end());
	cout << result << "\n";
	for (int i = 0; i < vec.size(); i++)
		cout << vec[i] << " ";
	cout << endl;
	system("pause");
	return 0;
}