/*
	위상 정렬을 이용해서 해결하는 문제
	코드 참조: https://lyzqm.blogspot.com/2017/04/1516.html
*/
#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int degree[501] = { 0, };
int N, n;
vector<int> vec[501];
int time[501], result[501];

void bfs() {
	queue<int> q;
	for (int i = 1; i <= N; i++) {
		if (degree[i] == 0) {
			q.push(i);
			result[i] = time[i];
		}
	}

	while (!q.empty()) {
		int front = q.front();
		q.pop();
		for (int i = 0; i < vec[front].size(); i++) {
			int e = vec[front][i];
			result[e] = max(result[e], result[front] + time[e]);
			if (--degree[e] == 0)
				q.push(e);
		}

	}
}


int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> n;
		time[i] = n;
		while (1) {
			cin >> n;
			if (n == -1)	break;
			vec[n].push_back(i);
			degree[i]++;
		}
	}
	bfs();
	for (int i = 1; i <= N; i++)
		cout << result[i] << "\n";
	system("pause");
	return 0;
}