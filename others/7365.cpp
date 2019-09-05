#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(pair<double, pair<int, int>> a, pair<double, pair<int, int>> b) {
	if (a.first < b.first)		//������������ ����
		return true;
	else
		return false;
}

int main(void) {
	vector<int> first;
	vector<int> second;
	vector < pair<double, pair<int, int>>> vec;
	int n;
	for (int i = 0; i < 3; i++) {
		cin >> n;
		first.push_back(n);
	}
	for (int i = 0; i < 7; i++) {
		cin >> n;
		second.push_back(n);
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 7; j++) {
			double re = (double)first[i] / second[j];
			cout << fixed;
			cout.precision(2);		//�Ҽ� ��° �ڸ������� ����
			vec.push_back({ re, {i+1, j+1} });
		}
	}
	sort(vec.begin(), vec.end(), compare);
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i].first << " " << vec[i].second.first << " " << vec[i].second.second << "\n";
	}

	system("pause");
	return 0;
}