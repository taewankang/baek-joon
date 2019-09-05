#include<iostream>
#include<string.h>
#include<string>
using namespace std;
int main(void) {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int location = 0;
		cin >> location;
		string str;
		cin >> str;
		string new_str = "";
		new_str += str.substr(0, location - 1);
		new_str += str.substr(location, str.length() - 1);
		cout << new_str << endl;
	}
	system("pause");
	return 0;
}