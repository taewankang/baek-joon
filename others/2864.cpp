#include<iostream>
#include<string.h>
#include<string>
using namespace std;
int main(void) {
	string A, B;
	cin >> A >> B;
	string min_A, min_B;
	string max_A, max_B;
	for (int i = 0; i < A.length(); i++) {
		if (A[i] == '6') {
			A[i] = '5';
		}
	}
	min_A = A;
	for (int i = 0; i < B.length(); i++) {
		if (B[i] == '6')
			B[i] = '5';
	}
	min_B = B;
	for (int i = 0; i < A.length(); i++) {
		if (A[i] == '5')
			A[i] = '6';
	}
	for (int i = 0; i < B.length(); i++) {
		if (B[i] == '5')
			B[i] = '6';
	}
	cout << stoi(min_A) + stoi(min_B) << " " << stoi(A) + stoi(B) << endl;
	system("pause");
	return 0;
}