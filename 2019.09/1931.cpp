#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool compare1(pair<int, int> a, pair<int, int> b) {
	if (a.second < b.second)
		return true;
	else if (a.second == b.second) {
		if (a.first < b.first)
			return true;
		else
			return false;
	}
	else
		return false;
}

int main(void) {
	int N, start, end, end_time = 0;
	scanf("%d", &N);
	vector<pair<int, int>> vec;
	bool find = false;
	int result = 0;
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &start, &end);
		vec.push_back({ start, end });
	}
	sort(vec.begin(), vec.end(), compare1);
	for (int i = 0; i < N; i++) {
		if (end_time <= vec[i].first) {
			end_time = vec[i].second;
			result++;
		}
	}
	cout << result << "\n";
	return 0;
}