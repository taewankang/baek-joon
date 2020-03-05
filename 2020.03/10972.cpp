/*
	-1 출력값을 만족하는지 우선 확인을 한다.
	뒤에서부터 확인하면서 다음이 있는 값을 찾아준다.
*/
#include<iostream>
#include<deque>
#include<algorithm>
#include<vector>
using namespace std;
int N, n;

bool check(deque<int> deq) {
	while (!deq.empty()) {
		if (deq.front() == N--)
			deq.pop_front();
		else
			return false;
	}
	return true;
}
int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> N;
	deque<int> deq;
	vector<int> vec;
	for (int i = 0; i < N; i++) {
		cin >> n;
		deq.push_back(n);
	}

	if (check(deq)) {
		cout << "-1\n";
		return 0;
	}

	int maximum = 0;
	while (1) {
		int num = deq.back();
		vec.push_back(deq.back());
		deq.pop_back();
		if (maximum > num) {
			sort(vec.begin(), vec.end());
			for (int i = 0; i < vec.size(); i++) {
				if (vec[i] > num) {
					deq.push_back(vec[i]);
					maximum = vec[i];
					break;
				}
			}
			break;
		}
		maximum = num;
	}
	for (int i = 0; i < vec.size(); i++) {
		if (vec[i] != maximum)
			deq.push_back(vec[i]);
	}
	while (!deq.empty()) {
		cout << deq.front() << " ";
		deq.pop_front();
	}
	cout << "\n";
	system("pause");
	return 0;
}