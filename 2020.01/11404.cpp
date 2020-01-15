/*
	�÷��̵� �˰����� �̿��ϴ� ����
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
		arr[a][b] != 0 ? arr[a][b] = min(arr[a][b], c) : (arr[a][b] = c);		//����ġ�� �ּڰ��� ������ �Ѵ�.
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
				if (j == i || k == i)	continue;		//������� �������� ���� ���� �����Ƿ� continue
				if (j == k)		continue;				//���İ��� ��尡 �ƴϹǷ� continue
				if (arr[j][i] == 0 || arr[i][k] == 0)	//�Ÿ��� ������ �ʾ� ���Ѵ��� ���·� �����ϱ� ������ continue
					continue;
				if (arr[j][k] == 0)						//���Ѵ��� ���·� �����ؾ� �ϱ� ������ continue
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