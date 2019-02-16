#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool compare(pair<int, long long> a, pair<int, long long> b) {
	if (a.second < b.second)
		return true;
	else if (a.second == b.second) {
		if (a.first > b.first)
			return true;
		else
			return false;
	}
	else
		return false;
}

int main(void) {
	int N, M;
	cin >> N >> M;	//문제 수    학생 수
	int s = 0;
	int student_num = 0;
	long long sum = 0;
	vector<int> score;
	for (int i = 0; i < N; i++) {
		cin >> s;
		score.push_back(s);
	}
	char correct;	//OX입력
	vector<pair<int, long long>> student(M);
	for (int i = 0; i < M; i++) {
		sum = 0;
		cin >> student_num;
		for (int j = 0; j < N; j++) {
			cin >> correct;
			if (correct == 'O')
				sum += score[j];
		}
		student[i] = { student_num, sum };		
	}
	sort(student.begin(), student.end(), compare);
	cout << student[student.size() - 1].first << " " << student[student.size() - 1].second << endl;
	system("pause");
	return 0;
}