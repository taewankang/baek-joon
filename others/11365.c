11365
#include<iostream>
#include<string>
#include<string.h>
using namespace std;
int main(void) {
	string str;
	while (1) {
		getline(cin, str);
		if (str == "END")
			break;

		for (int i = (str.length() -1); i >= 0; i--) {		//문자열의 뒤에서부터 출력
			cout << str.at(i);
		}
		cout << endl;
	}
	system("pause");
	return 0;
}