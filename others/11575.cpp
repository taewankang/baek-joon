#include<iostream>
#include<string.h>
#include<string>
using namespace std;
int main(void) {
	int T;
	cin >> T;
	for (int m = 0; m < T; m++) {
		int a, b;
		string str, result = "";
		cin >> a >> b;
		cin >> str;
		for (int i = 0; i < str.length(); i++) {
			char r = (a*(str[i] - 'A') + b) % 26 + 'A';
			result += r;
		}
		cout << result << endl;
	}
	system("pause");
	return 0;
}