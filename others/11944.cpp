#include<iostream>
#include<string.h>
#include<string>
using namespace std;
int main(void) {
	string N, M;
	cin >> N >> M;
	int n = stoi(N);
	string str="";
	for (int i = 0; i < n; i++) {
		str += N;
	}
	if (str.length() < stoi(M))
		cout << str << "\n";
	else
		cout << str.substr(0, stoi(M)) << "\n";
	system("pause");
	return 0;
}