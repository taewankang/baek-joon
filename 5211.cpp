#include<iostream>
#include<string.h>
#include<string>
using namespace std;
int main(void) {
	string str;
	cin >> str;
	int C = 0, A = 0;		//다장조: C    가단조: A

	for (int i = 0; i < str.length(); i++) {
		if (i == 0) {
			if (str[i] == 'C' || str[i] == 'F' || str[i] == 'G') {
				C++;
			}
			else if(str[i]=='A' || str[i] == 'D' || str[i] == 'E'){
				A++;
			}
		}
		else if (str[i] == '|') {
			if (str[i+1] == 'C' || str[i+1] == 'F' || str[i+1] == 'G') {
				C++;
			}
			else if (str[i+1] == 'A' || str[i+1] == 'D' || str[i+1] == 'E') {
				A++;
			}
		}
	}
	if (C > A)
		cout << "C-major\n";
	else if (C == A) {
		if (str[str.length() - 1] == 'C')
			cout << "C-major\n";
		else
			cout << "A-minor\n";
	}
	else
		cout << "A-minor\n";
	system("pause");
	return 0;
}