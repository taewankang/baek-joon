#include<iostream>
#include<string.h>
#include<string>
using namespace std;
int main(void) {
	int N;
	string str;
	cin >> N >> str;
	int hidden = 0;
	long long result = 0;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] >= '0' && str[i] <= '9') {
			hidden *= 10;
			hidden += str[i] - '0';
			
		}
		else {
			result += hidden;
			hidden = 0;
		}
	}
	if (str[str.length() - 1] >= '0' && str[str.length() - 1] <= '9')
		result += hidden;
	cout << result << endl;
	system("pause");
	return 0;
}