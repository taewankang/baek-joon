#include<iostream>
#include<vector>
#include<stack>
#include<string.h>
#include<string>
using namespace std;

int exception_func(string str) {	//예외처리 함수
	stack<char> s;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '(' || str[i] == '[') 
			s.push(str[i]);
		else if (str[i] == ')') {
			if (s.size() > 0 && s.top() == '(') 
				s.pop();
			else
				return 1;
		}
		else if (str[i] == ']') {
			if (s.size() > 0 && s.top() == '[')
				s.pop();
			else
				return 1;
		}
	}
	if (s.size() == 0)
		return 0;
	else
		return 1;
}

int solve_Func(string str) {		//문제 해결 함수	여는 소괄호: -1 여는 중괄호: -2
	int result = 0;
	stack<int> s;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '(')
			s.push(-1);
		else if (str[i] == '[')
			s.push(-2);
		else if (str[i] == ']') {
			int sum = 0;
			if (s.top() == -2) {
				s.pop();
				s.push(3);
			}
			else {
				while (s.top() != -2) {
					sum += s.top();
					s.pop();
				}
				s.pop();
				s.push(sum * 3);
			}
		}
		else if (str[i] == ')') {
			int sum = 0;
			if (s.top() == -1) {
				s.pop();
				s.push(2);
			}
			else {
				while (s.top() != -1) {
					sum += s.top();
					s.pop();
				}
				s.pop();
				s.push(sum * 2);
			}
		}
	}
	
	while (!s.empty()) {
		result += s.top();
		s.pop();
	}
	return result;
}

int main(void) {
	string str;
	cin >> str;
	if (exception_func(str)) {
		cout << "0\n";
		return 0;
	}
	cout << solve_Func(str) << "\n";
	system("pause");
	return 0;
}