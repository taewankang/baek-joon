/*
	1. A가 왼쪽으로 가고 B도 왼쪽으로 갈 때
	2. A가 왼쪽으로 가고 B는 오른쪽으로 갈 때
	3. A가 오른쪽으로 가고 B는 왼쪽으로 갈 때
	4. A가 오른쪽으로 가고 B도 오른쪽으로 갈 때

	1. A와 B 사이의 거리를 구한다. A와 B사이의 거리가 홀수라면 2의 n승의 이동으로는 만날 수 없기 때문에 -1를 반환해준다.
	2. A와 B의 중간 거리를 반으로 나눈 후 이를 2진법으로 바꾼다.
	3. 2진법으로 바꾼 0의 자리부터 값이 0이면 2, 3방법으로 움직이며 A와 B의 사이의 거리를 유지한다.
	4. 값이 1이라면 A는 오른쪽 B는 왼쪽으로 보내면서 BFS방식으로 이를 구현한다.

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
