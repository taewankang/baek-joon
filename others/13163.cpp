#include<iostream>
#include<string.h>
#include<string>
using namespace std;
int main(void) {
	int T;
	cin >> T;
	string str;
	cin.ignore();
	for (int i = 0; i < T; i++) {
		getline(cin, str);
		string result = "god";
		bool start = false;
		for (int j = 0; j < str.length(); j++) {
			if (str[j] == ' ' && start==false) {
				start = true;
			}
			if (start == true && str[j] >= 'a' && str[j] <= 'z')
				result += str[j];
		}
		cout << result << endl;
	}

	system("pause");
	return 0;
}