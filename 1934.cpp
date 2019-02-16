#include<iostream>
using namespace std;

int gcd(int n1, int n2) {		//최대공약수
	if (n1%n2 == 0)
		return n2;
	else
		return gcd(n2, n1%n2);
}

int main(void) {
	int A, B, T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> A >> B;
		int n1 = A, n2 = B;
		n1 /= gcd(A, B);
		cout << n1 * n2 << endl;
	}
	system("pause");
	return 0;
}
