#include<iostream>
#include<vector>
#include<string>
#include<string.h>
#include<algorithm>
using namespace std;
bool compare(pair<string, pair<int, pair<int, int>>> a, pair<string, pair<int, pair<int, int>>> b) {	//정렬 기준 함수
	if (a.second.first > b.second.first)
		return true;
	else if (a.second.first == b.second.first) {
		if (a.second.second.first < b.second.second.first) {
			return true;
		}
		else if (a.second.second.first == b.second.second.first) {
			if (a.second.second.second > b.second.second.second) {
				return true;
			}
			else if (a.second.second.second == b.second.second.second) {
				if (a.first < b.first) {
					return true;
				}
				else
					return false;
			}
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
	int N;
	cin >> N;
	vector<pair<string, pair<int, pair<int, int>>>> vec(100001);
	string name;
	int korean, eng, math;
	for (int i = 0; i < N; i++) {
		cin >> name >> korean >> eng >> math;
		vec[i].first = name;
		vec[i].second.first = korean;
		vec[i].second.second.first = eng;
		vec[i].second.second.second = math;
	}

	sort(vec.begin(), vec.end(), compare);
	for (int i = 0; i < N; i++) {
		cout << vec[i].first << "\n";
	}
	system("pause");
	return 0;
}