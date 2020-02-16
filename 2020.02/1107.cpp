#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
int arr[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
int N, M, m;

bool check(int num) {
	if (num < 0)
		return false;
	while (1) {
		if (num < 10) {
			if (arr[num] == -1)
				return false;
			return true;
		}
		if (arr[num % 10] == -1)
			return false;
		num /= 10;
	}
}

int find_nearest() {
	int mtemp = N, ptemp = N, temp = 100;

	while (1) {
		if (check(ptemp--)) {
			temp = ptemp + 1;
			break;
		}
		if (check(mtemp++)) {
			temp = mtemp - 1;
			break;
		}
	}
	int len = 0;
	len += abs(N - temp);
	while (1) {
		if (temp < 10) {
			len++;
			break;
		}
		temp /= 10;
		len++;
	}
	return len;
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		cin >> m;
		arr[m] = -1;
	}
	if (N == 100) {
		cout << 0 << "\n";
		return 0;
	}
	int diff = abs(N - 100);
	if (M == 10) {
		cout << diff << endl;
		return 0;

	}
	int remote = find_nearest();
	cout << min(diff, remote) << endl;
	system("pause");
	return 0;
}