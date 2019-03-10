#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int seo(int A, int B) {				//서로소 구하는 알고리즘
	if (B ? seo(B, A %B) : A == 1)
		return true;
	else
		return false;
}

int main(void) {
	int T, N;
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> N;
		int result = 0;
		for (int i = 1; i * i<= N ; i++) {
			if (N % i == 0 && seo(i, N/i)) {
				result++;
			}
		}
		if (N == 1)
			result = 1;
		cout << result << "\n";
	}
	system("pause");
	return 0;
}