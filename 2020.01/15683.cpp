#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int N, M, minimum = 987654321;
vector<pair<pair<int, int>, int>> vec;

vector<vector<int>> makeRange(vector<vector<int>> v, int y, int x, int cnt) {
	if (cnt == 1) {	//->
		for (int i = x + 1; i <= M; i++) {
			if (v[y][i] == 6)
				break;
			else if (v[y][i] == 0)
				v[y][i] = -1;
		}
	}
	else if (cnt == 2) {	//<-
		for (int i = x - 1; i > 0; i--) {
			if (v[y][i] == 6)
				break;
			else if (v[y][i] == 0)
				v[y][i] = -1;
		}
	}
	else if (cnt == 3) {	//^
		for (int i = y - 1; i > 0; i--) {
			if (v[i][x] == 6)
				break;
			else if (v[i][x] == 0)
				v[i][x] = -1;
		}
	}
	else if (cnt == 4) {	//v
		for (int i = y + 1; i <= N; i++) {
			if (v[i][x] == 6)
				break;
			else if (v[i][x] == 0)
				v[i][x] = -1;
		}
	}
	return v;
}

void recursive(int cnt, vector<vector<int>> room) {
	if (cnt == vec.size()) {
		int result = 0;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				if (room[i][j] == 0)
					result++;
			}
		}
		minimum > result ? minimum = result : NULL;
		return;
	}
	int y = vec[cnt].first.first;
	int x = vec[cnt].first.second;
	vector<vector<int>> v = room;
	if (vec[cnt].second == 5) {
		v = makeRange(v, y, x, 1);
		v = makeRange(v, y, x, 2);
		v = makeRange(v, y, x, 3);
		v = makeRange(v, y, x, 4);
		recursive(cnt + 1, v);
	}
	else if (vec[cnt].second == 4) {
		v = makeRange(v, y, x, 1);
		v = makeRange(v, y, x, 2);
		v = makeRange(v, y, x, 3);
		recursive(cnt + 1, v);

		v = room;
		v = makeRange(v, y, x, 2);
		v = makeRange(v, y, x, 3);
		v = makeRange(v, y, x, 4);
		recursive(cnt + 1, v);

		v = room;
		v = makeRange(v, y, x, 1);
		v = makeRange(v, y, x, 2);
		v = makeRange(v, y, x, 4);
		recursive(cnt + 1, v);

		v = room;
		v = makeRange(v, y, x, 1);
		v = makeRange(v, y, x, 3);
		v = makeRange(v, y, x, 4);
		recursive(cnt + 1, v);
	}
	else if (vec[cnt].second == 3) {
		v = makeRange(v, y, x, 1);
		v = makeRange(v, y, x, 3);
		recursive(cnt + 1, v);

		v = room;
		v = makeRange(v, y, x, 2);
		v = makeRange(v, y, x, 3);
		recursive(cnt + 1, v);

		v = room;
		v = makeRange(v, y, x, 2);
		v = makeRange(v, y, x, 4);
		recursive(cnt + 1, v);

		v = room;
		v = makeRange(v, y, x, 1);
		v = makeRange(v, y, x, 4);
		recursive(cnt + 1, v);
	}
	else if (vec[cnt].second == 2) {
		v = makeRange(v, y, x, 1);
		v = makeRange(v, y, x, 2);
		recursive(cnt + 1, v);

		v = room;
		v = makeRange(v, y, x, 3);
		v = makeRange(v, y, x, 4);
		recursive(cnt + 1, v);
	}
	else if (vec[cnt].second == 1) {
		v = makeRange(v, y, x, 1);
		recursive(cnt + 1, v);

		v = room;
		v = makeRange(v, y, x, 2);
		recursive(cnt + 1, v);

		v = room;
		v = makeRange(v, y, x, 3);
		recursive(cnt + 1, v);

		v = room;
		v = makeRange(v, y, x, 4);
		recursive(cnt + 1, v);
	}
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> N >> M;
	vector<vector<int>> room(N + 1);
	int n;
	for (int i = 1; i <= N; i++) {
		room[i].push_back(0);
		for (int j = 1; j <= M; j++) {
			cin >> n;
			if (n > 0 && n < 6)
				vec.push_back({ {i, j}, n });
			room[i].push_back(n);
		}
	}

	recursive(0, room);
	cout << minimum << endl;
	system("pause");
	return 0;
}