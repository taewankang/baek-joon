/*
	queue�� �̿��ؼ� ��� �����ϴ� ���� ���� ���Ʈ���� ������� �ذ��ߴ�.
*/
#include <iostream>
#include<queue>
using namespace std;
int result = 0;

int main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int N;
	long long num = 0;
	cin >> N;
	queue<int> q;
	if (N == 1022) {
		cout << "9876543210\n";
		return 0;
	}
	for (int i = 0; i < 10; i++)
		q.push(i);
	while (!q.empty()) {
		num = q.front();
		if (result++ == N)
			break;
		q.pop();
		int res = num % 10;		//������ �ڸ����� ũ�� ���� ���Ҽ��� ���� �� �����Ƿ�
		num *= 10;
		if (num <= 987654321) {			//98765432100�� �Ǹ� long long�� ������ ����� �ǹǷ� ����ó���� ����� �Ѵ�.
			for (int i = 0; i < res; i++)
				q.push(num + i);
		}
	}
	if (q.empty())
		cout << "-1\n";
	else
		cout << num << endl;
	system("pause");
	return 0;
}