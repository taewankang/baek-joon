#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, M, K;
int nutrient[11][11] = { 0, }, land[11][11] = { 0, };
int dir_y[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dir_x[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };
vector<vector<vector<int>>> tree;

void input() {
	cin >> N >> M >> K;
	int y, x, z;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> nutrient[i][j];		//겨울에 들어올 양분
			land[i][j] = 5;		//가장 처음에 양분은 모든 칸에 5만큼 들어있다.
		}
	}

	for (int i = 0; i < M; i++) {
		cin >> x >> y >> z;
		tree[x][y].push_back(z);
	}
}

void show() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++)
			cout << tree[i][j].size() << " ";
		cout << endl;
	}
}

void spring_summer() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			//spring
			sort(tree[i][j].begin(), tree[i][j].end());
			int dead = 0;
			vector<int> temp;

			for (int k = 0; k < tree[i][j].size(); k++) {
				int age = tree[i][j][k];
				if (land[i][j] >= age) {
					land[i][j] -= age;
					temp.push_back(age + 1);
				}
				else {
					dead += age / 2;
				}
			}

			//summer
			land[i][j] += dead;
			tree[i][j].clear();
			for (int k = 0; k < temp.size(); k++)
				tree[i][j].push_back(temp[k]);
		}
	}
}

void autumn() {
	vector<vector<vector<int>>> temp;
	temp.assign(11, vector<vector<int>>(11, vector<int>(0)));
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 0; k < tree[i][j].size(); k++) {
				if (tree[i][j][k] % 5 == 0) {		//5의 배수라면
					for (int d = 0; d < 8; d++) {
						int next_y = i + dir_y[d];
						int next_x = j + dir_x[d];
						if (next_y > 0 && next_y <= N && next_x > 0 && next_x <= N) {
							temp[next_y][next_x].push_back(1);
						}
					}
				}
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 0; k < temp[i][j].size(); k++) {
				tree[i][j].push_back(temp[i][j][k]);
			}
		}
	}
}

void winter() {
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			land[i][j] += nutrient[i][j];
}

int result() {
	int res = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			res += tree[i][j].size();
		}
	}
	return res;
}

void start() {
	for (int i = 0; i < K; i++) {
		spring_summer();
		autumn();
		winter();
	}
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	tree.assign(11, vector<vector<int>>(11, vector<int>(0)));
	input();
	start();
	cout << result() << endl;
	return 0;
}
