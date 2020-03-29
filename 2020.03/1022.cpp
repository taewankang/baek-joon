/*
	시간복잡도: N
	들어오는 값이 5000이 최대이므로 10000 * 10000배열에 소용돌이를 만든다고 생각한다.
	실제로 10000 * 100000의 배열을 만들어서 원하는 위치를 출력했더니 메모리 초과가...
	그래서 num값을 증가는 시키면서 우리가 원하는 위치에 값이 들어올 때만 배열에 저장을 해 출력을 하도록 했다.
*/

#include <iostream>
#include<algorithm>
#include<string>
#include<string.h>
#include<vector>
using namespace std;
int arr[50][5] = { 0, };
struct Dir {
	int y, x, cnt;
};
Dir dir[4] = { {0, 1, 1}, {-1, 0, 1}, {0, -1, 2}, {1, 0, 2} };
int r1, r2, c1, c2, leng;
void start() {
	int num = 1;
	int y = 5000, x = 5000;
	while (1) {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < dir[i].cnt; j++) {
				if (y - 5000 >= r1 && y - 5000 <= r2 && x - 5000 >= c1 && x - 5000 <= c2) {
					arr[y - 5000 - r1][x - 5000 - c1] = num;
					leng < num ? leng = num : NULL;
				}
				y += dir[i].y;
				x += dir[i].x;
				if (num++ == 110000000) {
					return;
				}
			}
			dir[i].cnt += 2;
		}
	}
}

int calculate_len(int num) {
	int len = 0;
	while (1) {
		if (num == 0)
			return len;
		num /= 10;
		len++;
	}
}

int main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	vector<string> vec(50, "");
	for (int i = 0; i < abs(r2 - r1); i++)
		vec.push_back("");
	cin >> r1 >> c1 >> r2 >> c2;
	start();

	int longest = calculate_len(leng);
	for (int i = 0; i <= abs(c2 - c1); i++) {		//가로
		for (int j = 0; j <= abs(r2 - r1); j++) {
			string tem = "";
			for (int k = 0; k <= longest - calculate_len(arr[j][i]) - 1; k++)		//이쁘게 출력하기 위해 최대 길이만큼 문자열에 추가하였다.
				tem += " ";
			tem += to_string(arr[j][i]);
			tem += " ";
			vec[j] += tem;
		}
	}

	for (int i = 0; i <= abs(r2 - r1); i++)
		cout << vec[i] << endl;
	return 0;
}
