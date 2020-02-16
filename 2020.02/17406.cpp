#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N, M, K;
vector<vector<int>> vec(51);
int result = 987654321;
struct Turn {
	int r, c, s;
};
Turn turn[7];

vector<vector<int>> rotating(int y1, int x1, int y2, int x2, vector<vector<int>> map) {
	int temp[51][51] = { 0, };
	int ty1 = y1, ty2 = y2, tx1 = x1, tx2 = x2;
	while (1) {
		if (ty1 == ty2) {
			for (int i = tx1; i <= tx2; i++)
				temp[ty1][i] = map[ty1][i];
			break;
		}
		else if (tx1 == tx2) {
			for (int i = ty1; i <= ty2; i++)
				temp[i][tx1] = map[i][tx1];
			break;
		}
		for (int i = tx1; i < tx2; i++)
			temp[ty1][i + 1] = map[ty1][i];
		for (int i = ty1; i < ty2; i++)
			temp[i + 1][tx2] = map[i][tx2];
		for (int i = tx2; i > tx1; i--)
			temp[ty2][i - 1] = map[ty2][i];
		for (int i = ty2; i > ty1; i--)
			temp[i - 1][tx1] = map[i][tx1];
		ty1++;
		ty2--;
		tx1++;
		tx2--;
	}

	for (int i = y1; i <= y2; i++) {
		for (int j = x1; j <= x2; j++) {
			map[i][j] = temp[i][j];
		}
	}
	return map;
}


void rotate_order(vector<int> v) {
	vector<vector<int>> map = vec;
	int x1, x2, y1, y2;
	for (int i = 0; i < K; i++) {
		y1 = turn[v[i]].r - turn[v[i]].s;
		x1 = turn[v[i]].c - turn[v[i]].s;
		y2 = turn[v[i]].r + turn[v[i]].s;
		x2 = turn[v[i]].c + turn[v[i]].s;
		map = rotating(y1, x1, y2, x2, map);
	}

	for (int i = 1; i <= N; i++) {
		int sum = 0;
		for (int j = 1; j <= M; j++) {
			sum += map[i][j];
		}
		result > sum ? result = sum : NULL;
	}
}

void permu() {
	vector<int> v;
	for (int i = 0; i < K; i++)
		v.push_back(i);

	do {
		rotate_order(v);
	} while (next_permutation(v.begin(), v.end()));
}


int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> N >> M >> K;
	int n;
	for (int i = 1; i <= N; i++) {
		vec[i].push_back(0);
		for (int j = 1; j <= M; j++) {
			cin >> n;
			vec[i].push_back(n);
		}
	}

	for (int i = 0; i < K; i++) {
		int r, c, s;
		cin >> r >> c >> s;
		turn[i].r = r;
		turn[i].c = c;
		turn[i].s = s;
	}

	permu();
	cout << result << endl;
	system("pause");
	return 0;
}