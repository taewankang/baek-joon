#include<iostream>
#include<vector>
#include<deque>
using namespace std;
int N, K, L, X;
int arr[101][101] = { 0, };
int result = 0;
vector<pair<int, char>> vec;
vector<pair<int, int>> snake;
struct Dir {
	int y, x;
};

Dir dir[4] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };	// 상, 하, 좌, 우

void start() {
	int y = 1, x = 1, fidx = 0;
	snake.push_back({ 1, 1 });
	arr[y][x] = 0;
	int cnt = 0;
	int d = 3;
	while (1) {
		if (y < 1 || y > N || x < 1 || x > N) {
			break;
		}
		if (cnt < vec.size()) {
			if (result < vec[cnt].first) {
				y += dir[d].y;
				x += dir[d].x;
			}
			else if (result == vec[cnt].first) {
				if (d == 0) {
					if (vec[cnt].second == 'D')
						d = 3;
					else
						d = 2;
				}
				else if (d == 1) {
					if (vec[cnt].second == 'D')
						d = 2;
					else
						d = 3;
				}
				else if (d == 2) {
					if (vec[cnt].second == 'D')
						d = 0;
					else
						d = 1;
				}
				else if (d == 3) {
					if (vec[cnt].second == 'D')
						d = 1;
					else
						d = 0;
				}
				y += dir[d].y;
				x += dir[d].x;
				cnt++;
			}
		}
		else {
			y += dir[d].y;
			x += dir[d].x;
		}

		if (arr[y][x] == 1) {
			result++;
			break;
		}

		if (arr[y][x] == 0) {
			snake.push_back({ y, x });
			arr[y][x] = 1;
			arr[snake[fidx].first][snake[fidx].second] = 0;
			fidx++;
		}

		else if (arr[y][x] == -1) {
			arr[y][x] = 1;
			snake.push_back({ y, x });
		}
		result++;
	}
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> N >> K;
	int x, y;
	for (int i = 0; i < K; i++) {
		cin >> y >> x;
		arr[y][x] = -1;			//사과가 있는 위치 저장
	}

	char c;

	cin >> L;
	for (int i = 0; i < L; i++) {
		cin >> X >> c;
		vec.push_back({ X, c });
	}

	start();

	cout << result << endl;
	system("pause");
	return 0;
}

