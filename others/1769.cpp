#include<iostream>
#include<string.h>
#include<string>
using namespace std;
int main(void) {
	string str;
	int N = 0;
	cin >> str;
	int count = 0;
	if (str.length() > 1)
		count = 1;
	for (int i = 0; i < str.length(); i++) {
		N += str[i] - '0';
	}

	while (N >= 10) {
		int solution2 = 0;
		while (N >= 1) {
			solution2 += N % 10;
			N /= 10;
		}
		N = solution2;
		count++;
	}
	cout << count << endl;
	if (N % 3 == 0)
		cout << "YES\n";
	else
		cout << "NO\n";
	system("pause");
	return 0;
}