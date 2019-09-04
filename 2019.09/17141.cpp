#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<map>
using namespace std;
int N, M, minimum=999999;
vector<pair<int, int>> virus_location;
vector<vector<int>> all_case;
bool check[2501];
int counting;
int x_arr[4] = { 1, -1, 0, 0 }, y_arr[4] = { 0, 0, 1, -1 };

int bfs(vector<vector<int>> vec, vector<int> cases) {
	counting = 0;
	int maximum = 0;
	for (int i = 0; i < cases.size(); i++) 
		vec[virus_location[cases[i]].first][virus_location[cases[i]].second] = 2;		//M개의 바이러스를 생성
	queue<pair<pair<int, int>, int>> q;
	bool check2[51][51] = { 0, };
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (vec[i][j] == 1) {
				check2[i][j] = true;
				counting++;
			}
			if (vec[i][j] == 2) {
				q.push({ {i, j}, 0 });
				check2[i][j] = true;
				counting++;
			}				
		}
	}

	while (!q.empty()) {
		int first = q.front().first.first;		//세로
		int second = q.front().first.second;		//가로
		int third = q.front().second;
		if (third > maximum)
			maximum = third;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int next_x = second + x_arr[i];
			int next_y = first + y_arr[i];
			if (next_x > 0 && next_x <= N && next_y > 0 && next_y <= N && check2[next_y][next_x] != true) {
				check2[next_y][next_x] = true;
				counting++;
				q.push({ { next_y, next_x }, third + 1});
			}
		}
	}
	return maximum;
}

void select_virus(int start, int depth) {
	if (depth == M) {
		vector<int> vc;
		for (int i = 1; i <= virus_location.size(); i++)
			if(check[i] == true)
				vc.push_back(i);
		all_case.push_back(vc);
		return;
	}
	for (int i = start; i < virus_location.size(); i++) {
		if (check[i] == true)
			continue;
		check[i] = true;
		select_virus(i, depth + 1);
		check[i] = false;
	}
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> N >> M;
	int n;
	vector<vector<int>> vec(N + 1);
	virus_location.push_back({ 0, 0 });
	for (int i = 1; i <= N; i++) {
		vec[i].push_back(0);
		for (int j = 1; j <= N; j++) {
			cin >> n;
			if (n == 2) {
				virus_location.push_back({ i, j });	//세로 가로	인덱스는 1부터 시작
				vec[i].push_back(0);
			}
			else 
				vec[i].push_back(n);
		}
	}
	select_virus(1, 0);
	for (int i = 0; i < all_case.size(); i++) {
		int a = bfs(vec, all_case[i]);
		if (a < minimum && counting == N*N)
			minimum = a;
	}
	if (minimum == 999999)
		minimum = -1;
	cout << minimum << endl;
	system("pause");
	return 0;
}