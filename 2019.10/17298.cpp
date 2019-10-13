#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int N, n;
	cin >> N;
	vector<pair<int, int>> vec(N + 1);
	stack<int> s;

	for (int i = 1; i <= N; i++) {
		cin >> n;
		vec[i] = { n, i };
	}

	vec[N].second = -1;
	s.push(vec[N].first);
	for (int i = N - 1; i > 0; i--) {
		if (s.top() > vec[i].first) {
			vec[i].second = s.top();
			s.push(vec[i].first);
		}
		else {
			while (1) {
				if (s.empty()) {		//비어있다면
					s.push(vec[i].first);
					vec[i].second = -1;
					break;
				}
				if (vec[i].first < s.top()) {
					vec[i].second = s.top();
					s.push(vec[i].first);
					break;
				}
				s.pop();
			}
		}
	}

	for (int i = 1; i <= N; i++)
		cout << vec[i].second << " ";
	cout << endl;
	system("pause");
	return 0;
}