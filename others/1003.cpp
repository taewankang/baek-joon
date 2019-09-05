#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(void) {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		vector<pair<int, pair<int, int>>> vec;
		int N;
		cin >> N;
		vec.push_back({ 0, {1, 0} });
		vec.push_back({ 1, {0, 1} });
		for (int i = 2; i <= N; i++) {
			vec.push_back({ i, {vec[i - 1].second.first + vec[i - 2].second.first, vec[i - 1].second.second + vec[i - 2].second.second} });
		}
		cout << vec[N].second.first << " " << vec[N].second.second << "\n";
	}
	system("pause");
	return 0;
