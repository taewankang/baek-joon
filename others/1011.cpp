#include<iostream>
using namespace std;
int main(void) {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		long long start, des, count = 0, distance = 0;
		int max = 1;
		cin >> start >> des;
		distance = des - start;
		if (distance == 1) {
			cout << "1\n";
			continue;
		}
		else if (distance == 2) {
			cout << "2\n";
			continue;
		}
		else if (distance == 3) {
			cout << "3\n";
			continue;
		}
		int copy_dis = distance;

		distance /= 2;
		for (max = 1; distance > 0; max++) {
			distance -= max;
		}
		max -= 1;
		long long tot = 0;
		for (int j = 1; j <= max; j++)
			tot += j;
		tot *= 2;
		if (tot - max < copy_dis)
			cout << max*2 << endl;
		else
			cout << max*2 - 1 << endl;
	}
	system("pause");
	return 0;
}