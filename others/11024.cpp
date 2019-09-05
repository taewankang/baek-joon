#include<iostream>
#include<string.h>
#include<string>
using namespace std;
int main(void) {
	int T;
	cin >> T;
	cin.ignore();
	string str;
	for (int i = 0; i < T; i++) {
		getline(cin, str);
		int result = 0, num=0;
		for (int j = 0; j < str.length(); j++) {
			if (str[j] >= '0' && str[j] <= '9') {
				num *= 10;
				num += str[j] - '0';
			}
			else if (str[j] == ' ') {
				result += num;
				num = 0;
			}				
		}
		result += num;
		cout << result << endl;
	}

	system("pause");
	return 0;
}