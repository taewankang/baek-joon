10845
#include<iostream>
#include<queue>
#include<string.h>
#include<string>
using namespace std;
int main(void) {
	int num, n;
	queue<int> que;
	string str;
	cin >> num;

	for (int i = 0; i < num; i++) {
		cin >> str;
		if (str == "push") {
			cin >> n;
			que.push(n);
		}
		else if (str == "pop") {
			if (que.size() > 0) {
				cout << que.front() << endl;
				que.pop();
			}
			else if (que.size() == 0)
				cout << "-1" << endl;
		}
		else if (str == "size")
			cout << que.size() << endl;
		else if (str == "empty") {
			if (que.size() == 0)
				cout << "1" << endl;
			else
				cout << "0" << endl;
		}
		else if (str == "front") {
			if (que.size() > 0)
				cout << que.front() << endl;
			else
				cout << "-1" << endl;
		}
		else if (str == "back") {
			if (que.size() > 0)
				cout << que.back() << endl;
			else
				cout << "-1" << endl;
		}
	}
	system("pause");
	return 0;
}