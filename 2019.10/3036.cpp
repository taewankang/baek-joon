#include<iostream>
#include<vector>
using namespace std;
int GCD(int n1, int n2) {
	while (n2 != 0) {
		int temp = n1 % n2;
		n1 = n2;
		n2 = temp;
	}
	return n1;
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int N, n;
	cin >> N;
	vector<int> vec(N + 1);
	for (int i = 1; i <= N; i++) {
		cin >> n;
		vec[i] = n;
	}

	for (int i = 2; i <= N; i++) {
		if (vec[1] > vec[i]) {
			int gcd = GCD(vec[1], vec[i]);
			cout << vec[1] / gcd << "/" << vec[i] / gcd << endl;
		}
		else {
			int gcd = GCD(vec[i], vec[1]);
			cout << vec[1] / gcd << "/" << vec[i] / gcd << endl;
		}
	}
	system("pause");
	return 0;
}