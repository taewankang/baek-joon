#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
vector<int> vec;
void prime() {
	for (int i = 2; i < 10000; i++) {
		bool p = true;
		for (int j = 2; j*j <= i; j++) {
			if (i%j == 0) {
				p = false;
				break;
			}
		}
		if (p == true)
			vec.push_back(i);
	}
}

int main(void) {
	int T, n;
	cin >> T;
	prime();
	for (int i = 0; i < T; i++) {
		cin >> n;
		int m = 0;
		while (1) {
			if (vec[m] > n)
				break;
			m++;
		}
		int diff = 10000;
		int a, b;
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < m; k++) {
				if ((vec[j] + vec[k] == n) && (diff > abs(vec[j]-vec[k]))) {
					diff = abs(vec[j] - vec[k]);
					a = vec[j];	b = vec[k];
				}
			}
		}
		if (a < b)
			cout << a << " " << b << "\n";
		else
			cout << b << " " << a << "\n";
 	}
	system("pause");
	return 0;
}