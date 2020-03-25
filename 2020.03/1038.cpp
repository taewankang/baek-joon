/*
	queue를 이용해서 모든 감소하는 수를 구해 브루트포스 방식으로 해결했다.
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
		int res = num % 10;		//마지막 자리수의 크기 까지 감소수를 만들 수 있으므로
		num *= 10;
		if (num <= 987654321) {			//98765432100이 되면 long long의 범위도 벗어나게 되므로 예외처리를 해줘야 한다.
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