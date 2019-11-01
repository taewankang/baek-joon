#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int N, n;
	cin >> N;
	priority_queue<int, vector<int>, less<int>> max_heap;
	priority_queue<int, vector<int>, greater<int>> min_heap;
	cin >> n;
	max_heap.push(n);
	vector<int> vec(N);
	cout << n << endl;
	vec[0] = n;
	for (int i = 1; i < N; i++) {
		cin >> n;
		if (max_heap.size() > min_heap.size()) 	//min_heap에 넣어야 함
			min_heap.push(n);
		else max_heap.push(n);
		if (max_heap.top() > min_heap.top()) {
			int mintop = min_heap.top();
			int maxtop = max_heap.top();
			max_heap.pop();
			min_heap.pop();
			max_heap.push(mintop);
			min_heap.push(maxtop);
		}

		cout << max_heap.top() << "\n";
	}
	return 0;
}
