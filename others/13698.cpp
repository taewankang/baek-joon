#include<iostream>
#include<vector>
#include<string.h>
#include<string>
using namespace std;
int main(void) {
	string str;
	cin >> str;
	vector<int> vec(5);
	int temp = 0;
	for (int i = 0; i < 5; i++) {
		vec[i] = i;
	}

	for (int i = 0; i < str.length(); i++) {
		if (str[i] == 'A') {
			temp = vec[1];
			vec[1] = vec[2];
			vec[2] = temp;
		}
		else if (str[i] == 'B') {
			temp = vec[1];
			vec[1] = vec[3];
			vec[3] = temp;
		}
		else if (str[i] == 'C') {
			temp = vec[1];
			vec[1] = vec[4];
			vec[4] = temp;
		}
		else if (str[i] == 'D') {
			temp = vec[2];
			vec[2] = vec[3];
			vec[3] = temp;
		}
		else if (str[i] == 'E') {
			temp = vec[2];
			vec[2] = vec[4];
			vec[4] = temp;
		}
		else if (str[i] == 'F') {
			temp = vec[3];
			vec[3] = vec[4];
			vec[4] = temp;
		}
	}
	for (int i = 1; i < 5; i++) {
		if (vec[i] == 1)
			cout << i << "\n";
	}
	for (int i = 1; i < 5; i++) {
		if (vec[i] == 4)
			cout << i << "\n";
	}
	system("pause");
	return 0;
}