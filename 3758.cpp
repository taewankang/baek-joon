#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(pair<pair<int, int>, pair<int, int>> a, pair<pair<int, int>, pair<int, int>> b) {
	if (a.first.second < b.first.second)
		return true;
	else if (a.first.second == b.first.second) {
		if (a.second.first > b.second.first)
			return true;
		else if (a.second.first == b.second.first) {
			if (a.second.second < b.second.second)
				return true;
			else
				return false;
		}
		else
			return false;
	}
	else
		return false;
}// 팀 번호   총 점수    제출 횟수    낸 순서

int main(void) {
	int T;
	cin >> T;
	for (int o = 0; o < T; o++) {
		vector<pair<pair<int, int>, int>> vec;
		vector<pair<int, int>> team_info(10001);
		vector<int> total_score;			//팀 점수의 총합을 저장
		vector<int> submit_count;			//팀의 총 제출 횟수
		submit_count.push_back(0);	//팀의 숫자대로 인덱스에 저장하기 위해
		total_score.push_back(0);
		int n, k, t, m;
		cin >> n >> k >> t >> m;
		for (int i = 0; i <= n * k; i++) {
			team_info[i].first = 0;
			team_info[i].second = 0;
		}

		for (int j = 0; j < m; j++) {
			int ID, num, s;
			cin >> ID >> num >> s;
			vec.push_back({ {ID, num}, s });
		}
		vector<int> last_submit(n + 1);			//마지막 제출 시간이 더 빠른 팀을 구하는 벡터
		fill(last_submit.begin(), last_submit.end(), 0);
		int weight = 1;
		for (int i = vec.size() - 1; i >= 0; i--) {
			if (last_submit[vec[i].first.first] == 0) {		//last_submit의 인덱스에 저장된 숫자가 작을수록 늦게 제출했단 뜻
				last_submit[vec[i].first.first] = weight;
				weight++;
			}
		}
		for (int i = 0; i < m; i++) {
			team_info[k * (vec[i].first.first - 1) + vec[i].first.second].first++;	//문제가 들어온 횟수
			if (team_info[k*(vec[i].first.first - 1) + vec[i].first.second].second < vec[i].second)		//인덱스 1부터 시작함
				team_info[k*(vec[i].first.first - 1) + vec[i].first.second].second = vec[i].second;		//문제의 최대점수
		}

		for (int i = 0; i < n; i++) {
			int sum = 0;
			int count = 0;
			for (int j = 0; j < k; j++) {
				count += team_info[i * k + j + 1].first;	//각 팀마다 제출 횟수 구하기
				sum += team_info[i * k + j + 1].second;		//각 팀마다 총점 구하기
			}
			total_score.push_back(sum);		//1팀의 총점은 인덱스 1에 저장 됨
			submit_count.push_back(count);
		}

		vector<pair<pair<int, int>, pair<int, int>>> result_team;
		for (int i = 1; i <= n; i++)
			result_team.push_back({ {i ,total_score[i] }, { submit_count[i], last_submit[i]} });
		sort(result_team.begin(), result_team.end(), compare);
		for (int i = 0; i < result_team.size(); i++) {
			if (result_team[i].first.first == t) {
				cout << n-i << "\n";
				break;
			}
		}
	}
	system("pause");
	return 0;
}