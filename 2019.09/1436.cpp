#include<iostream>
using namespace std;
int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	long long start = 665, counting = 0;
	int N;
	cin >> N;
	if (N == 1) {
		cout << 666 << endl;
		system("pause");
		return 0;
	}

	while (1) {
		if (counting == N)
			break;
		start++;
		int same = 0;
		int copy_num = start;
		while (copy_num >= 1) {
			if (copy_num % 10 == 6)
				same++;
			else
				same = 0;
			if (same == 3) {
				counting++;
				break;
			}
			copy_num /= 10;
		}
	}
	cout << start << endl;
	system("pause");
	return 0;
}