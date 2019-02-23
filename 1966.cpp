#include<iostream>
#include<queue>
using namespace std;
int main(void) {
	int T, N, M, prior;
	cin >> T;
	for (int i = 0; i < T; i++) {
		queue<pair<int, int>> q;
		priority_queue<int> pq;
		int result = 0;
		bool same = false;
		cin >> N >> M;
		for (int j = 0; j < N; j++) {
			cin >> prior;
			pq.push(prior);
			q.push({ j, prior });
		}

		while (!pq.empty()) {
			for (int j = 0; j < q.size(); j++) {
				if (q.front().first == M && q.front().second == pq.top()) {
					cout << result + 1 << "\n";
					same = true;
					break;
				}
				else if (q.front().second == pq.top()) {
					pq.pop();
					q.pop();
					result++;
				}
				else {
					q.push({ q.front().first, q.front().second });
					q.pop();
				}
			}
			if (same == true)
				break;
		}
	}
	system("pause");
	return 0;
}