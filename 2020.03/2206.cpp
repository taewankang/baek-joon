#include <iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<string>
#include<string.h>
using namespace std;
bool check[2][1001][1001] = { false, };
int map[1001][1001] = { 0, };
int N, M;
struct Dir { int y, x; };
Dir dir[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

void bfs() {
	queue<pair<pair<int, int>, pair<int, int>>> q;
	q.push({ { 1, 1 },{0, 1} });	//y, x, ���� ���� �վ���? ���°�ΰ�?
	check[0][1][1] = true;
	check[1][1][1] = true;
	int result = 123456789;
	while (!q.empty()) {
		int y = q.front().first.first;
		int x = q.front().first.second;
		int visit = q.front().second.first;
		int cnt = q.front().second.second;
		q.pop();
		if (y == N && x == M)
			result > cnt ? result = cnt : NULL;
		for (int i = 0; i < 4; i++) {
			int next_y = y + dir[i].y;
			int next_x = x + dir[i].x;
			if (next_y > 0 && next_y <= N && next_x > 0 && next_x <= M) {
				if (map[next_y][next_x] == 0 && visit == 0 && !check[0][next_y][next_x]) {		//�������� �� ���� ���� �ƴϰ� ���� ���� �� �վ��ٸ�
					q.push({ { next_y, next_x }, {0, cnt + 1} });
					check[0][next_y][next_x] = true;
				}
				else if (map[next_y][next_x] == 0 && visit == 1 && !check[1][next_y][next_x]) {	//�������� �� ���� ���� �ƴϰ� ���� ���� ���� �ִٸ�
					q.push({ {next_y, next_x}, {1, cnt + 1} });
					check[1][next_y][next_x] = true;
				}
				else if (map[next_y][next_x] == 1 && visit == 0 && !check[0][next_y][next_x]) {	//�������� �� ���� ���̰� ���� ���� ���� ���ٸ�
					q.push({ {next_y, next_x}, {1, cnt + 1} });
					check[1][next_y][next_x] = true;
				}
			}
		}
	}
	result == 123456789 ? result = -1 : NULL;
	cout << result << endl;
}

//���� �ν��� ������ ���� �ƴ϶�� --> �������� �Ѿ �� �ִ�.
//���� �μ��� �ʾҰ� ������ ���� �ƴ϶�� --> �׳� �����ִ�.
//���� �μ��� �ʾҰ� ������ ���̶�� --> �����ִ�..

int main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < str.length(); j++) {
			map[i][j + 1] = str[j] - '0';
		}
	}
	bfs();

	system("pause");
	return 0;
}
