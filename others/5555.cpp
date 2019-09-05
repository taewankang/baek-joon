#include<iostream>
#include<string.h>
#include<string>
using namespace std;
int main(void) {
	string str, s;
	int N, count = 0;
	cin >> str;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> s;
		s += s;
		for (int j = 0; j < s.length() / 2; j++) {
			if (str == s.substr(j, str.length())) {
				count++;
				break;
			}
		}
	}
	cout<<count<<endl;

	system("pause");
	return 0;
}