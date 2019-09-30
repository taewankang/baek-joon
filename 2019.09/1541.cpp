#include<iostream>
#include<string.h>
#include<string>
#include<vector>
#include<queue>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	string str;
	cin >> str;
	queue<int> int_queue;
	queue<char> char_queue;

	int num = 0, result = 0;
	bool minus_start = false;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] >= '0' && str[i] <= '9') {
			num *= 10;
			num += str[i] - '0';
		}
		else {
			int_queue.push(num);
			char_queue.push(str[i]);
			num = 0;
		}
	}
	int_queue.push(num);
	result += int_queue.front();
	int_queue.pop();
	while (!int_queue.empty()) {
		if (char_queue.front() == '-') 
			minus_start = true;
		if (minus_start == false) {
			result += int_queue.front();
			int_queue.pop();
			char_queue.pop();
		}
		else {
			result -= int_queue.front();
			int_queue.pop();
			char_queue.pop();
		}
	}
	cout << result << endl;
	system("pause");
	return 0;
}