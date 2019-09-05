#include<iostream>
#include<string.h>
#include<string>
#include<math.h>
using namespace std;
int main(void) {
	int N = 0;
	cin >> N;
	for (int j = 0; j < N; j++) {
		string str;
		cin >> str;
		int letter = 0, number = 0;

		for (int i = 0; i < 3; i++) {
			letter += (str[i] - 'A') * pow(26, 2 - i);
		}
		for (int i = 0; i < 4; i++) {
			number = stoi(str.substr(4, 8));
		}
		if (abs(letter - number) < 100)
			cout << "nice\n";
		else
			cout << "not nice\n";
	}
	system("pause");
	return 0;
}