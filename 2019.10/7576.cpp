#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int N, M, n;
vector<vector<int>> vec(1001);
int arr_x[4] = { 1, -1, 0, 0 };
int arr_y[4] = { 0, 0, 1, -1 };
bool check[1001][1001] = { 0, };
int maximum = 0;
void bfs(vector<pair<int, int>> ik) {
	queue<pair<int, int>> q;
	for (int i = 0; i < ik.size(); i++) {
		q.push({ ik[i].first, ik[i].second });
	}

	while (!q.empty()) {
		int fir = q.front().first;	//세로
		int sec = q.front().second;	//가로
		q.pop();
		for (int i = 0; i < 4; i++) {
			//cout << fir + arr_y[i] << " " << sec + arr_x[i] << endl;
			if (fir + arr_y[i] > 0 && fir + arr_y[i] <= M && sec + arr_x[i] > 0 && sec + arr_x[i] <= N && check[fir + arr_y[i]][sec + arr_x[i]] == false) {
				vec[fir + arr_y[i]][sec + arr_x[i]] = vec[fir][sec] + 1;
				check[fir + arr_y[i]][sec + arr_x[i]] = true;
				q.push({ fir + arr_y[i], sec + arr_x[i] });
			}
		}
	}
}
int main(void) {
	bool all = true;
	cin >> N >> M;
	vector<pair<int, int>> ik;
	for (int i = 1; i <= M; i++) {
		vec[i].push_back(0);
		for (int j = 1; j <= N; j++) {
			cin >> n;
			if (n == 0)
				all = false;
			else if (n == 1) {
				ik.push_back({ i, j });	//세로 가로
				check[i][j] = true;
			}
			else if (n == -1)
				check[i][j] = true;
			vec[i].push_back(n);
		}
	}
	if (all == true) {
		cout << "0\n";
		return 0;
	}

	bfs(ik);


	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++) {
			if (vec[i][j] == 0) {
				cout << "-1";
				return 0;
			}
			if (maximum < vec[i][j]) {
				maximum = vec[i][j];
			}
		}
	}
	cout << maximum - 1 << endl;
	return 0;
}