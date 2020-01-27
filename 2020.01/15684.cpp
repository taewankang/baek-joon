#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N, M, H, result;
int arr[31][11] = { 0, };
vector<pair<int, int>> vec;
bool visit[271] = { false, };
bool finish = false;

bool check() {
	for (int i = 1; i <= N; i++) {		//가로
		int ladder = i;
		for (int j = 1; j <= H; j++) {		//세로
			if (arr[j][ladder] != 0) {
				if (ladder == 1)
					ladder++;
				else if (ladder == N)
					ladder--;
				else
					arr[j][ladder] == arr[j][ladder - 1] ? ladder-- : ladder++;
			}
		}
		if (ladder != i) {
			return false;
		}
	}
	return true;
}

void make_ladder(vector<int> v) {

	for (int i = 0; i < v.size(); i++) {
		if (arr[vec[v[i]].first][vec[v[i]].second + 1] != 0)
			return;
	}

	for (int i = 0; i < v.size(); i++) {
		arr[vec[v[i]].first][vec[v[i]].second] = vec[v[i]].second + 1;
		arr[vec[v[i]].first][vec[v[i]].second + 1] = vec[v[i]].second + 1;
	}

	if (check()) {
		finish = true;
	}
	for (int i = 0; i < v.size(); i++) {
		arr[vec[v[i]].first][vec[v[i]].second] = 0;
		arr[vec[v[i]].first][vec[v[i]].second + 1] = 0;
	}
}

void permu(int idx, int cnt, int num) {
	if (cnt == num) {
		vector<int> v;
		for (int i = 0; i < vec.size(); i++) {
			if (visit[i] == true)
				v.push_back(i);
		}
		make_ladder(v);
		return;
	}

	for (int i = idx; i < vec.size(); i++) {
		if (visit[i] == true)	continue;
		visit[i] = true;;
		permu(i, cnt + 1, num);
		visit[i] = false;
	}
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> N >> M >> H;
	int a, b;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		arr[a][b] = b + 1;
		arr[a][b + 1] = b + 1;
	}

	for (int i = 1; i <= H; i++)
		for (int j = 1; j < N; j++)
			if (arr[i][j] == 0)
				vec.push_back({ i, j });

	if (check())
		result = 0;

	else {
		for (int i = 1; i <= 3; i++) {
			if (!finish) {
				result = i;
				permu(0, 0, i);
			}
			else
				break;
		}
		if (!finish)
			result = -1;
	}
	cout << result << endl;
	system("pause");
	return 0;
}