#include<iostream>
#include<vector>
#include<string>
#include<string.h>
using namespace std;
int main(void) {
	string str;
	getline(cin, str);
	vector<long long> vec;
	bool minus = false;
	long long num = 0;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '-')
			minus = true;
		if (str[i] != ' ' && str[i] != '-') {
			num += str[i] - '0';
		}
		if (str[i] == ' ') {
			if (minus == true)
				num *= -1;
			num /= 10;
			vec.push_back(num);
			num = 0;
			minus = false;
		}
		num *= 10;
	}
	vec.push_back(num / 10);
	for (int i = 0; i < vec.size() - 1; i++) {
		if (vec[i] > vec[i + 1]) {
			cout << "Bad\n";
			system("pause");
			return 0;
		}
	}
	cout << "Good\n";
	system("pause");
	return 0;
}