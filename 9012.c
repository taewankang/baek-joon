9012
#include<iostream>
#include<vector>
#include<string.h>
#include<string>
using namespace std;
int main(void) {
	int num;
	cin >> num;
	string str;
	int count = 0;
	for (int i = 0; i < num; i++) {
		cin >> str;
		count = 0;
		for (int j = 0; j < str.size(); j++) {
			if (str.at(j) == '(') {	//여는 괄호를 입력했을 경우 count값을 증가시킨다.
				count++;
			}
			else if (str.at(j) == ')') {	//닫는 괄호를 입력했을 경우 count값을 감소시킨다.
				count--;
			}
			if (count < 0)	만약 ')'를 먼저 입력했을 경우 count값이 0보다 작아지므로 이를 방지하기 위해
				break;
		}
		if (count == 0)	//괄호의 열고 닫음이 올바르게 입력되었을 때
			cout << "YES" << endl;
		else	//올바르게 입력되지 않았을 때
			cout << "NO" << endl;
	}
	system("pause");
	return 0;
}