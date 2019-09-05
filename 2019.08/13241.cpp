#include<iostream>
using namespace std;
long long gcd(long long A, long long B) {
	int n;
	while (B != 0) {
		n = A % B;
		A = B;
		B = n;
	}
	return A;
}

int main(void) {
	long long A, B;
	cin >> A >> B;
	if (A < B) {
		int temp = A;
		A = B;
		B = temp;
	}
	long long C = gcd(A, B);
	A /= C;
	cout << A * B << "\n";

	system("pause");
	return 0;
}

