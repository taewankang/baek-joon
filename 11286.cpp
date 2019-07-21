#include<iostream>
#include<queue>
using namespace std;
int main(void) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	int N, n;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> n;
		if (n > 0) {
			pq.push({ n, 1 });
		}
		else if(n < 0){
			pq.push({ -n, -1 });
		}
		else if (n == 0) {
			if (pq.size() > 0) {
				if(pq.top().second == 1)
					cout << pq.top().first << "\n";
				else if (pq.top().second == -1) {
					cout << -pq.top().first << "\n";
				}
				pq.pop();
			}
			else if (pq.size() == 0)
				cout << "0\n";
		}
	}
	system("pause");
	return 0;
}