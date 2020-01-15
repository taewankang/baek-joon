/*
	플루이드 알고리즘을 이용하는 문제
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int arr[101][101] = { 0, };
int N, M;
void input() {		
	int a, b, c;
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		arr[a][b] != 0 ? arr[a][b] = min(arr[a][b], c) : (arr[a][b] = c);		//가중치는 최솟값만 저장을 한다.
	}
}

void show() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++)
			cout << arr[i][j] << " ";
		cout << "\n";
	}
}

void solve() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= N; k++) {
				if (j == i || k == i)	continue;		//출발점과 도착점이 같은 경우는 없으므로 continue
				if (j == k)		continue;				//거쳐가는 노드가 아니므로 continue
				if (arr[j][i] == 0 || arr[i][k] == 0)	//거리가 계산되지 않아 무한대인 상태로 존재하기 때문에 continue
					continue;
				if (arr[j][k] == 0)						//무한대의 상태로 존재해야 하기 때문에 continue
					arr[j][k] = 987654321;
				arr[j][k] = min(arr[j][k], arr[j][i] + arr[i][k]);
			}
		}
	}
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> N >> M;
	input();
	solve();
	show();
	system("pause");
	return 0;
}