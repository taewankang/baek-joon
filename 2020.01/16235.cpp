#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int N, M, K;
vector<vector<int>> map(11);
int origin[11][11];
vector<vector<int>> tree(101);
struct Dir {
	int y, x;
};

Dir dir[8] = { {1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1} };
void spring() {		//봄, 여름
	for (int i = 1; i <= N * N; i++)
		sort(tree[i].begin(), tree[i].end());

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int idx = N * (i - 1) + j;
			int dead = 0;
			int cnt = 0;
			for (int k = 0; k < tree[idx].size(); k++) {
				if (origin[i][j] >= tree[idx][k]) {
					origin[i][j] -= tree[idx][k];
					tree[idx][k]++;
				}
				else {
					cnt++;
					dead += (tree[idx][k] / 2);
				}
			}
			origin[i][j] += dead;
			for (int k = 0; k < cnt; k++)
				tree[idx].pop_back();
		}
	}
}

void autumn() {		//가을
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int idx = N * (i - 1) + j;
			for (int l = 0; l < tree[idx].size(); l++) {
				if (tree[idx][l] % 5 == 0) {
					for (int k = 0; k < 8; k++) {
						int next_y = i + dir[k].y;
						int next_x = j + dir[k].x;
						if (next_y > 0 && next_y <= N && next_x > 0 && next_x <= N) {
							int idx2 = N * (next_y - 1) + next_x;
							tree[idx2].push_back(1);
						}
					}
				}
			}
		}
	}
}

void winter() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++)
			origin[i][j] += map[j][i];
	}
}
int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> N >> M >> K;
	int n;
	for (int i = 1; i <= N; i++) {			//초기화
		for (int j = 1; j <= N; j++)
			origin[i][j] = 5;
	}

	for (int i = 1; i <= N; i++) {			//맵 입력
		map[i].push_back(0);
		for (int j = 1; j <= N; j++) {
			cin >> n;
			map[i].push_back(n);
		}
	}

	int x, y, z;
	for (int i = 0; i < M; i++) {			//나무 위치 입력
		cin >> x >> y >> z;
		tree[N * (y - 1) + x].push_back(z);
	}

	for (int i = 0; i < K; i++) {
		spring();
		autumn();
		winter();
	}

	int sum = 0;
	for (int i = 1; i <= N * N; i++) {
		sum += tree[i].size();
	}
	cout << sum << endl;
	system("pause");
	return 0;
}