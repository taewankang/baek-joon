#include<iostream>
using namespace std;
int main(void) {
	long long A, B;
	cin >> A >> B;
	if (B < A) {
		long long temp = A;
		A = B;
		B = temp;
	}
	long long sum = A + B;
	sum *= (B - A + 1) / 2;
	if ((B - A + 1) % 2 != 0) {
		sum += A + ((B - A + 1) / 2);
	}
	cout << sum << "\n";
	system("pause");
	return 0;
}