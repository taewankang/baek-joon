4949
#include<iostream>
#include<stack>
#include<string.h>
#include<string>
using namespace std;

int main(void) {
	string s;
	bool balance = true;
	while (1) {
		balance = true;
		stack<int> vec;
		getline(cin, s);
		if (s == ".")
			break;
		for (int i = 0; i < s.length(); i++) {
			if (s.at(i) == '(') 
				vec.push(1);
			else if (s.at(i) == '[')
				vec.push(0);
			else if (s.at(i) == ')'){		//닫는 괄호가 들어오면 스택의 크기가 0이 아님을 확인한 후 가장 위에가 해당 괄호에 해당하는지 확인하고 pop한다.
				if (vec.size() == 0) {
					balance = false;
					break;
				}
				if(vec.top() == 1)
					vec.pop();
				else {
					balance = false;
					break;
				}
			}
			else if (s.at(i) == ']') {
				if (vec.size() == 0) {
					balance = false;
					break;
				}
				if (vec.top() == 0) {
					vec.pop();
				}
				else {
					balance = false;
					break;
				}
			}
		}
		if (balance == false || vec.size() != 0)	//균형이 맞지 않는다면 no를 출력한다.
			cout << "no" << endl;
		else
			cout << "yes" << endl;
	}
	system("pause");
	return 0;
}