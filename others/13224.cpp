#include<iostream>
#include<string.h>
#include<string>
#include<vector>
using namespace std;

int main(void) {
	string str;
	cin >> str;
	vector<int> vec;
	for (int i = 0; i < 4; i++) {
		vec.push_back(i);
	}
	int temp = 0;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == 'A') {
			temp = vec[1];
			vec[1] = vec[2];
			vec[2] = temp;
		}
		else if (str[i] == 'B') {
			temp = vec[2];
			vec[2] = vec[3];
			vec[3] = temp;
		}
		else if (str[i] == 'C') {
			temp = vec[1];
			vec[1] = vec[3];
			vec[3] = temp;
		}
	}
	for (int i = 1; i < 4; i++) {
		if (vec[i] == 1)
			cout << i << "\n";
	}
	system("pause");
	return 0;
}