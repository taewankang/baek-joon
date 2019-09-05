10828
#include<iostream>
#include<stack>
#include<string>
#include<string.h>
using namespace std;
int main(void) {
	int num = 0;
	cin >> num;
	string str;
	stack<int> st;
	int n;
	for (int i = 0; i < num; i++) {
		cin >> str;
		if (str == "push") {
			cin >> n;
			st.push(n);
		}
		else if (str == "pop") {
			if (st.size() != 0) {
				cout << st.top() << endl;
				st.pop();
			}
			else if (st.size() == 0)
				cout << "-1" << endl;
		}
		else if (str == "size") {
			cout << st.size() << endl;
		}
		else if (str == "empty") {
			if (st.size() == 0)
				cout << "1" << endl;
			else
				cout << "0" << endl;
		}
		else if (str == "top") {
			if (st.size() == 0)
				cout << "-1" << endl;
			else
				cout << st.top() << endl;
		}
	}
	system("pause");
	return 0;
}