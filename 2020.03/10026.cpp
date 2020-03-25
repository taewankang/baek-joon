/*
	�Ϲ� ����� ������ bfs�� �̿��ؼ� ���� ���� reset()�Լ��� �̿��ؼ� �迭�� �ʱ�ȭ ���״�.
	�׸��� R�� ���� �ִ� �κ��� G�� �ٲ� �� �ٽ� bfs�� �̿��ؼ� ������ ���ߴ�.
*/
#include <iostream>
#include<queue>
#include<string>
#include<string.h>
using namespace std;
int N;
char arr[101][101];
struct Dir { int y, x; };
Dir dir[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
bool check[101][101] = { false, };
void bfs(int y, int x) {
	queue<pair<int, int>> q;
	char c = arr[y][x];
	q.push({ y, x });
	check[y][x] = true;
	while (!q.empty()) {
		int new_y = q.front().first;
		int new_x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int next_y = new_y + dir[i].y;
			int next_x = new_x + dir[i].x;
			if (next_y > 0 && next_y <= N && next_x > 0 && next_x <= N && !check[next_y][next_x] && arr[next_y][next_x] == c) {
				check[next_y][next_x] = true;
				q.push({ next_y ,next_x });
			}
		}
	}
}

int start() {
	int res = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (!check[i][j]) {
				res++;
				bfs(i, j);
			}
		}
	}
	return res;
}

void reset() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			arr[i][j] == 'R' ? arr[i][j] = 'G' : NULL;
			check[i][j] = false;
		}
	}
}

int main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	string str;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> str;
		for (int j = 0; j < N; j++) {
			arr[i][j + 1] = str[j];
		}
	}
	int first = start();
	reset();
	int second = start();
	cout << first << " " << second << endl;
	system("pause");
	return 0;
}