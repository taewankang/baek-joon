#include<iostream>
#include<string>
#include<vector>
#include<string.h>
#include<stdio.h>
using namespace std;
int main(void) {
	int N;
	cin >> N;
	string str;

	for (int i = 0; i < N; i++) {
		vector<char> vec(27);
		char c;
		cin.ignore();
		getline(cin, str);
		for (int j = 0; j < 26; j++) {
			cin >> c;
			vec[j] = c;
		}
		for (int j = 0; j < str.length(); j++) {
			if (str[j] >= 'A' && str[j] <= 'Z')
				cout << vec[str[j] - 'A'];
			else
				cout << " ";
		}
		cout << "\n";
	}
	system("pause");
	return 0;
}