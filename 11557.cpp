#include<iostream>
#include<vector>
#include<string.h>
#include<string>
#include<algorithm>
using namespace std;
bool compare(pair<string, int> a, pair<string, int> b) {
	if (a.second < b.second)
		return true;
	else
		return false;
}

int main(void) {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		vector <pair<string, int>> vec;
		int N;
		cin >> N;
		string str;
		int num;
		for (int j = 0; j < N; j++) {
			cin >> str >> num;
			vec.push_back({ str, num });
		}
		sort(vec.begin(), vec.end(), compare);
		cout << vec[vec.size() - 1].first << endl;
	}

	system("pause");
	return 0;
}