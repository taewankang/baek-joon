#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool compare(pair<int, int> a, pair<int, int> b) {	//정렬 기준이 되는 함수
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
	int N, x, y;
	cin >> N;
	vector<pair<int, int>> vec;

	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		vec.push_back(make_pair(x, y));
	}
	sort(vec.begin(), vec.end(), compare);
	for (int i = 0; i < vec.size(); i++) {
		printf("%d %d\n", vec[i].first, vec[i].second);
	}
	system("pause");
	return 0;
}