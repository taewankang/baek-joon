#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) {
	if (a.second.second < b.second.second)
		return true;
	else
		return false;
}

int main(void) {
	int N, n;
	cin >> N;
	stack<pair<int, int>> s;	//입력받은 값    순서
	vector<pair<int, pair<int, int>>> vec;	//입력받은 값   구할 정답     순서
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;	//입력받은 값    순서

	for (int i = 0; i < N; i++) {
		cin >> n;
		s.push({ n, i + 1 });
	}

	while (!s.empty()) {
		q.push({ s.top().first, s.top().second });
		s.pop();
		while (1) {
			if (q.size() > 0 && s.size() > 0 && s.top().first > q.top().first) {
				vec.push_back({ q.top().first , {s.size(), q.top().second} });
				q.pop();
			}
			else if (q.size() > 0 && s.size() > 0 && s.top().first < q.top().first) {
				q.push({ s.top().first , s.top().second});
				s.pop();
			}
			else {
				break;
			}
		}
	}
	while (!q.empty()) {
		vec.push_back({q.top().first, { 0, q.top().second }});
		q.pop();
	}
	sort(vec.begin(), vec.end(), compare);
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i].second.first << " ";
	}
	cout << "\n";
	system("pause");
	return 0;
}