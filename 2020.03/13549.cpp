#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define MAX 100000
int N, K;
bool check[MAX + 1] = { 0, };
int bfs() {
	queue<pair<int, int>> q;
	q.push({ N, 0 });
	check[N] = true;
	while (!q.empty()) {
		int front = q.front().first;
		int time = q.front().second;
		q.pop();
		if (front == K) {
			return time;
		}
		if (front * 2 <= MAX && check[front * 2] == false) {
			q.push({ front * 2, time });
			check[front * 2] = true;
		}
		if (front > 0 && check[front - 1] == false) {
			q.push({ front - 1, time + 1 });
			check[front - 1] = true;
		}
		if (front < MAX && check[front + 1] == false) {
			q.push({ front + 1, time + 1 });
			check[front + 1] = true;
		}
	}
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> N >> K;
	cout << bfs() << endl;

	system("pause");
	return 0;
}