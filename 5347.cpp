#include<iostream>
using namespace std;
long long LCM(int& a, int& b) {
	int num = 1;
	for (int i = 1; i <= a; i++) {
		if (a%i == 0 && b%i == 0) {
			a /= i;
			b /= i;
			num *= i;
		}
	}
	return num*a*b;
}

int main(void) {
	int N, a, b;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		if (a < b) {		//a가 더 크도록
			int temp = a;
			a = b;
			b = temp;
		}
		cout<< LCM(a, b) << "\n";
	}
	system("pause");
	return 0;
}