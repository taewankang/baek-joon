#include<iostream>
#include<string.h>
#include<string>
using namespace std;

int main(void) {
	int N;
	cin >> N;
	string str;
	cin >> str;
	int result = 0;
	bool couple = false;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == 'S') {
			result++;
		}
		else if (i < str.length() - 1 && str[i] == 'L' && str[i + 1] == 'L') {
			i++;
			result++;
			couple = true;
		}
	}
	if (couple == true)
		result++;
	cout << result << endl;
	system("pause");
	return 0;
}