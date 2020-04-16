/*
	1. A�� �������� ���� B�� �������� �� ��
	2. A�� �������� ���� B�� ���������� �� ��
	3. A�� ���������� ���� B�� �������� �� ��
	4. A�� ���������� ���� B�� ���������� �� ��

	1. A�� B ������ �Ÿ��� ���Ѵ�. A�� B������ �Ÿ��� Ȧ����� 2�� n���� �̵����δ� ���� �� ���� ������ -1�� ��ȯ���ش�.
	2. A�� B�� �߰� �Ÿ��� ������ ���� �� �̸� 2�������� �ٲ۴�.
	3. 2�������� �ٲ� 0�� �ڸ����� ���� 0�̸� 2, 3������� �����̸� A�� B�� ������ �Ÿ��� �����Ѵ�.
	4. ���� 1�̶�� A�� ������ B�� �������� �����鼭 BFS������� �̸� �����Ѵ�.

*/

#include <iostream>
#include<string>
#include<string.h>
#include<vector>
#include<algorithm>
#include<math.h>
#include<queue>
using namespace std;
int N, A, B;
struct Duck {
	int A, B, day;
};
string find_binary(int diff) {
	string str = "";
	while (1) {
		if (diff == 0)
			break;
		diff % 2 == 1 ? str += '1' : str += '0';
		diff /= 2;
	}
	return str;
}

int bfs(string str) {
	queue<Duck> q;
	q.push({ A, B, 0 });

	while (!q.empty()) {
		int a = q.front().A;
		int b = q.front().B;
		int day = q.front().day;
		int moving = pow(2, day);
		q.pop();
		if (a == b) {
			return day;
		}
		if (day < str.length()) {
			if (str[day] == '1') {
				if (a + moving <= N && b - moving > 0) {
					q.push({ a + moving, b - moving, day + 1 });
				}
			}
			else {
				if (a + moving <= N && b + moving <= N) {
					q.push({ a + moving, b + moving, day + 1 });
				}
				if (a - moving > 0 && b - moving > 0) {
					q.push({ a - moving, b - moving, day + 1 });
				}
			}
		}
	}
	return -1;
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int temp_A = 0, temp_B = 0;
	cin >> N >> temp_A >> temp_B;
	A = min(temp_A, temp_B);
	B = max(temp_A, temp_B);

	int diff = (B - A);
	if (diff % 2) {
		cout << "-1\n";
		return 0;
	}

	diff /= 2;
	string str = find_binary(diff);
	cout << bfs(str) << endl;

	system("pause");
	return 0;
}
