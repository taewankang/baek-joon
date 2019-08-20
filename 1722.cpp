#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
long long fac[21];
void factorial() {
	long long result = 1;
	fac[0] = 1;
	fac[1] = 1;
	for (int i = 2; i <= 19; i++)
		fac[i] = fac[i - 1] * i;
}

void one_func(long long num, int N) {
	vector<bool> check(N + 1, false);
	vector<int> vec;
	int n = 1, copy_N = N;
	bool eq = false;
	while (num > 0) {
		if (n <= copy_N) {
			if (check[n] == true) {
				n++;
				continue;
			}
			if (num > fac[N - 1]) {
				num -= fac[N - 1];
				n++;
			}
			if (num <= fac[N - 1]) {
				if (check[n] == false) {
					vec.push_back(n);
					check[n] = true;
					N--;
					if (num == 1) {
						for (int i = 1; i <= copy_N; i++) {
							if (check[i] == false)
								vec.push_back(i);
						}
						num -= 1;
					}
					n = 1;
				}
			}
		}
		else
			n = 1;
	}
	for (int i = 0; i < vec.size(); i++)
		cout << vec[i] << " ";
	cout << "\n";
}


void two_func(vector<int> vec, int N) {
	long long result = 0;
	vector<bool> check(N + 1, false);
	for (int i = 0; i < vec.size(); i++) {
		check[vec[i]] = true;
		for (int j = 1; j < vec[i]; j++) {
			if (check[j] == false) {
				result += fac[vec.size() - i - 1];
			}
		}
	}
	cout << result + 1 << "\n";
}

int main(void) {
	long long N, K;
	cin >> N >> K;
	factorial();
	if (K == 1) {
		long long k;
		cin >> k;
		one_func(k, N);
	}
	else {
		vector<int> vec;
		int n;
		for (int i = 0; i < N; i++) {
			cin >> n;
			vec.push_back(n);
		}
		two_func(vec, N);
	}
	system("pause");
	return 0;
}