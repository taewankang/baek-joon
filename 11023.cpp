#include<iostream>
#include<string.h>
#include<string>
using namespace std;
int main(void) {
	string str;
	getline(cin, str);
	int result = 0;
	int change = 0;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] >= '0' && str[i] <= '9') {
			change *=10;
			change += str[i] - '0';
		}
		else if (str[i] == ' ') {
			result += change;
			change = 0;		
		}
	}
	result += change;
	cout << result << endl;
	system("pause");
	return 0;
}