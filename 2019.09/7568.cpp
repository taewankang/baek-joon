#include<iostream>
#include<vector>
using namespace std;
int N;
vector<pair<pair<int, int>, int>> order(vector<pair<pair<int, int>, int>> vec) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == j)
				continue;
			if (vec[i].first.first < vec[j].first.first && vec[i].first.second < vec[j].first.second)
				vec[i].second++;
		}
	}
	return vec;
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int height, weight;
	cin >> N;
	vector<pair<pair<int, int>, int>> vec(N + 1);
	for (int i = 0; i < N; i++) {
		cin >> weight >> height;
		vec[i] = { {weight, height}, 1 };
	}
	vec = order(vec);
	for (int i = 0; i < N; i++)
		cout << vec[i].second << " ";
	cout << endl;
	return 0;
}