#include<iostream>
#include<string.h>
#include<string>
using namespace std;
int main(void) {
	string str;
	while (1) {
		cin >> str;
		int num_one = 0;
		if (str == "#")
			break;
		for (int i = 0; i < str.length() - 1; i++) {
			if (str[i] == '1') {
				num_one++;
			}
		}
		if (str[str.length() - 1] == 'e') {
			if (num_one % 2 == 0) 		//1이 짝수개 있고 짝수 패리티라면
				str[str.length() - 1] = '0';
			else
				str[str.length() - 1] = '1';
		}
		else if (str[str.length() - 1] == 'o') {
			if (num_one % 2 == 0)
				str[str.length() - 1] = '1';
			else
				str[str.length() - 1] = '0';
		}
		cout << str << "\n";
	}
	system("pause");
	return 0;
}