#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main(void) {
	int N, M, from, to;
	cin >> N >> M;
	priority_queue<int, vector<int>, greater<int>> q;
	vector<vector<int>> vec(32002);
	int indegree[32002] = { 0, };
	for (int i = 0; i < M; i++) {
		cin >> from >> to;
		vec[from].push_back(to);
		indegree[to]++;
	}
	for (int i = 1; i <= N; i++) {
		if (indegree[i] == 0) {
			q.push(i);
		}
	}
	while (!q.empty()) {
		int now = q.top();
		q.pop();
		indegree[now]--;
		cout << now << " ";
		for (int next : vec[now]) {
			indegree[next]--;
			if (indegree[next] == 0)
				q.push(next);
		}
	}
	system("pause");
	return 0;
}