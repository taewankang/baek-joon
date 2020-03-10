#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	string A, B;
	int minimum = 123456789;
	cin >> A >> B;
	for (int i = 0; i <= B.length() - A.length(); i++) {
		int sum = 0;
		for (int j = 0; j < A.length(); j++) {
			if (B[i + j] != A[j])
				sum++;
		}
		minimum > sum ? minimum = sum : NULL;
	}
	cout << minimum << endl;
	system("pause");
	return 0;
}