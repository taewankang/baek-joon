#include<iostream>
#include<string.h>
#include<string>
using namespace std;
int main(void) {
	string str;
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> str;
		string A = "", B = "";
		if (str.length() % 2 != 0)
			str += str;
		for (int j = 0; j < str.length(); j++) {
			if (j % 2 == 0)
				A += str[j];
			else
				B += str[j];
		}
		cout << A << "\n" << B << "\n";
	}
	system("pause");
	return 0;
}