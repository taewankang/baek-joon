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
			else if (s.at(i) == ')'){		//�ݴ� ��ȣ�� ������ ������ ũ�Ⱑ 0�� �ƴ��� Ȯ���� �� ���� ������ �ش� ��ȣ�� �ش��ϴ��� Ȯ���ϰ� pop�Ѵ�.
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
		if (balance == false || vec.size() != 0)	//������ ���� �ʴ´ٸ� no�� ����Ѵ�.
			cout << "no" << endl;
		else
			cout << "yes" << endl;
	}
	system("pause");
	return 0;
}