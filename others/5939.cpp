#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
	if (a.first.first < b.first.first)	//시, 분, 초 순서로 오름차순으로 정렬
		return true;
	else if (a.first.first == b.first.first) {
		if (a.first.second < b.first.second)
			return true;
		else if (a.first.second == b.first.second) {
			if (a.second < b.second)
				return true;
			else
				return false;
		}
		else
			return false;
	}
	else
		return false;
}

int main(void) {
	vector<pair<pair<int, int>, int>> vec;
	int N, Hour, Min, Sec;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> Hour >> Min >> Sec;
		vec.push_back({ { Hour, Min }, Sec });
	}
	sort(vec.begin(), vec.end(), compare);
	for (int i = 0; i < N; i++)
		cout << vec[i].first.first << " " << vec[i].first.second << " " << vec[i].second << "\n";
	system("pause");
	return 0;
}