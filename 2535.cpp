#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {	������ ������������ ����
	if (a.second > b.second)
		return true;
	else
		return false;
}

int main(void) {
	int N;
	int country;
	int student_num;
	int score;
	bool b = false;
	int num = 0;
	vector<pair<pair<int, int>, int>> vec;
	int country_max = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> country >> student_num >> score;
		if (country_max < country)
			country_max = country;
		vec.push_back({{country, student_num}, score });
	}
	sort(vec.begin(), vec.end(), compare);
	vector<int> v(country_max);	//�������� ������ ������ ����
	fill(v.begin(), v.end(), 0);
	for (int i = 0; i < N; i++) {
		b = false;
		if (v[vec[i].first.first-1] < 2) {	//�� ���󿡼� 2�� ���ϸ� ���� �� �����Ƿ�
			v[vec[i].first.first - 1]++;
			cout << vec[i].first.first << " " << vec[i].first.second << "\n";
			num++;
		}
		if (num == 3)
			break;
	}
	system("pause");
	return 0;
}