#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int N, M;
vector<vector<int>> vec(302);
struct Dir { int y, x; };
Dir dir[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
bool check[302][302] = { false, };

void input() {
	int n;
	for (int i = 1; i <= N; i++) {
		vec[i].push_back(0);
		for (int j = 1; j <= M; j++) {
			cin >> n;
			vec[i].push_back(n);
		}
	}
}

void copy_vector(vector<vector<int>> temp) {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++)
			vec[i][j] = temp[i][j];
	}
}

void year_later() {			//일년이 지나는 함수
	vector<vector<int>> temp(302);
	for (int i = 1; i <= N; i++) {
		temp[i].push_back(0);
		for (int j = 1; j <= M; j++)
			temp[i].push_back(vec[i][j]);
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			int cnt = 0;
			if (vec[i][j]) {
				for (int k = 0; k < 4; k++) {
					int new_y = i + dir[k].y;
					int new_x = j + dir[k].x;
					if (new_y > 0 && new_y <= N && new_x > 0 && new_x <= M && !vec[new_y][new_x])
						cnt++;
				}
				temp[i][j] - cnt < 0 ? temp[i][j] = 0 : temp[i][j] -= cnt;
			}
		}
	}
	copy_vector(temp);
}

void bfs(int y, int x) {
	check[y][x] = true;
	queue<pair<int, int>> q;
	q.push({ y, x });
	while (!q.empty()) {
		int new_y = q.front().first;
		int new_x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int next_y = new_y + dir[i].y;
			int next_x = new_x + dir[i].x;
			if (next_y > 0 && next_y <= N && next_x > 0 && next_x <= M && !check[next_y][next_x] && vec[next_y][next_x]) {
				check[next_y][next_x] = true;
				q.push({ next_y, next_x });
			}
		}
	}
}

void reset() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++)
			check[i][j] = false;
	}
}

bool is_divide() {
	int cnt = 0;
	reset();
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (vec[i][j] && !check[i][j]) {
				if (cnt == 0) {
					cnt++;
					bfs(i, j);
				}
				else 		//끝났다는 것
					return true;
			}
		}
	}
	return false;
}

bool final_check() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (vec[i][j])		//녹을 때까지 두 덩이로 분류가 된게 아니라면
				return false;
		}
	}
	return true;        //요기서 return true를 안해줘서 계속 틀렸다....
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> N >> M;
	input();

	int result = 0;
	while (1) {
		result++;
		year_later();
		if (is_divide())	//두 덩이로 분류가 됐다면
			break;
		if (final_check()) {
			result = 0;
			break;
		}
	}
	cout << result << "\n";
	return 0;
}