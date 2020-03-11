#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define MAX 2000
int N, minimum = 123456789;
bool check[MAX][MAX];
struct Emo {
	int screen = 0, clip = 0, cnt = 0;
};

void bfs() {
	queue<Emo> q;
	q.push({ 1, 0, 0 });
	check[1][0] = true;
	while (!q.empty()) {
		int screen = q.front().screen;
		int clip = q.front().clip;
		int cnt = q.front().cnt;
		q.pop();
		if (screen == N) {
			minimum = cnt;
			break;
		}
		if (screen > 0 && screen < MAX && !check[screen][screen]) {
			check[screen][screen] = true;
			q.push({ screen, screen, cnt + 1 });
		}
		if (screen + clip > 0 && screen + clip <= MAX && !check[screen + clip][clip]) {
			check[screen + clip][clip] = true;
			q.push({ screen + clip, clip, cnt + 1 });
		}
		if (screen > 0 && !check[screen - 1][clip]) {
			check[screen - 1][clip] = true;
			q.push({ screen - 1, clip, cnt + 1 });
		}
	}
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> N;
	bfs();
	cout << minimum << endl;
	system("pause");
	return 0;
}