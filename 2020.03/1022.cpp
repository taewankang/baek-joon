/*
	�ð����⵵: N
	������ ���� 5000�� �ִ��̹Ƿ� 10000 * 10000�迭�� �ҿ뵹�̸� ����ٰ� �����Ѵ�.
	������ 10000 * 100000�� �迭�� ���� ���ϴ� ��ġ�� ����ߴ��� �޸� �ʰ���...
	�׷��� num���� ������ ��Ű�鼭 �츮�� ���ϴ� ��ġ�� ���� ���� ���� �迭�� ������ �� ����� �ϵ��� �ߴ�.
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
	for (int i = 0; i <= abs(c2 - c1); i++) {		//����
		for (int j = 0; j <= abs(r2 - r1); j++) {
			string tem = "";
			for (int k = 0; k <= longest - calculate_len(arr[j][i]) - 1; k++)		//�̻ڰ� ����ϱ� ���� �ִ� ���̸�ŭ ���ڿ��� �߰��Ͽ���.
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
