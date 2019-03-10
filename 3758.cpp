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
}// �� ��ȣ   �� ����    ���� Ƚ��    �� ����

int main(void) {
	int T;
	cin >> T;
	for (int o = 0; o < T; o++) {
		vector<pair<pair<int, int>, int>> vec;
		vector<pair<int, int>> team_info(10001);
		vector<int> total_score;			//�� ������ ������ ����
		vector<int> submit_count;			//���� �� ���� Ƚ��
		submit_count.push_back(0);	//���� ���ڴ�� �ε����� �����ϱ� ����
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
		vector<int> last_submit(n + 1);			//������ ���� �ð��� �� ���� ���� ���ϴ� ����
		fill(last_submit.begin(), last_submit.end(), 0);
		int weight = 1;
		for (int i = vec.size() - 1; i >= 0; i--) {
			if (last_submit[vec[i].first.first] == 0) {		//last_submit�� �ε����� ����� ���ڰ� �������� �ʰ� �����ߴ� ��
				last_submit[vec[i].first.first] = weight;
				weight++;
			}
		}
		for (int i = 0; i < m; i++) {
			team_info[k * (vec[i].first.first - 1) + vec[i].first.second].first++;	//������ ���� Ƚ��
			if (team_info[k*(vec[i].first.first - 1) + vec[i].first.second].second < vec[i].second)		//�ε��� 1���� ������
				team_info[k*(vec[i].first.first - 1) + vec[i].first.second].second = vec[i].second;		//������ �ִ�����
		}

		for (int i = 0; i < n; i++) {
			int sum = 0;
			int count = 0;
			for (int j = 0; j < k; j++) {
				count += team_info[i * k + j + 1].first;	//�� ������ ���� Ƚ�� ���ϱ�
				sum += team_info[i * k + j + 1].second;		//�� ������ ���� ���ϱ�
			}
			total_score.push_back(sum);		//1���� ������ �ε��� 1�� ���� ��
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