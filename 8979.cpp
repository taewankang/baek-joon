#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(pair<pair<int, int>, pair<int, int>> a, pair<pair<int, int>, pair<int, int>> b) {
	if (a.first.second > b.first.second)
		return true;
	else if (a.first.second == b.first.second) {
		if (a.second.first > b.second.first)
			return true;
		else if (a.second.first == b.second.first) {
			if (a.second.second > b.second.second)
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
	int N, K, j=1;
	bool change = false;
	int country, gold, silver, bronze;
	cin >> N >> K;
	vector<pair<pair<int, int>, pair<int, int>>> vec;
	vector<int> ranking(N+1);

	for (int i = 0; i < ranking.size(); i++) {
		ranking[i] = i + 1;
	}
	for (int i = 0; i < N; i++) {
		cin >> country >> gold >> silver >> bronze;
		vec.push_back({ {country, gold}, {silver, bronze} });
	}
	sort(vec.begin(), vec.end(), compare);
	for (int i = 0; i < N - 1; i++) {
		if (vec[i].first.second == vec[i + 1].first.second && vec[i].second.first == vec[i + 1].second.first && vec[i].second.second == vec[i + 1].second.second) {
			ranking[i + 1] = ranking[i];
		}
	}
	
	for (int i = 0; i < vec.size(); i++) {
		if (vec[i].first.first == K) {
			cout << ranking[i] << "\n";
			break;
		}
	}
	system("pause");
	return 0;
}