#include<iostream>
#include<deque>
#include<string>
using namespace std;
int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	string AC, str;
	int T, n;
	char c;
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> AC >> n >> str;
		if (n == 0) {
			bool err = false;
			for (int i = 0; i < AC.length(); i++) {
				if (AC[i] == 'D') {
					cout << "error\n";
					err = true;
					break;
				}
			}
			if (!err) {
				cout << "[]\n";
				continue;
			}
			else continue;
		}
		string num;
		bool order = true;
		deque<int> deq;
		for (int i = 1; i < str.length() - 1; i++) {
			if (str[i] == ',') {
				deq.push_back(stoi(num));
				num = "";
			}
			else
				num += str[i];
		}
		deq.push_back(stoi(num));

		for (int i = 0; i < AC.length(); i++) {
			if (AC[i] == 'R')
				order == true ? order = false : order = true;
			else if (AC[i] == 'D') {
				if (deq.empty()) {
					cout << "error\n";
					break;
				}
				order ? deq.pop_front() : deq.pop_back();
			}

			if (i == AC.length() - 1) {
				cout << "[";
				while (!deq.empty()) {
					if (order) {
						cout << deq.front();
						deq.pop_front();
					}
					else {
						cout << deq.back();
						deq.pop_back();
					}
					if (deq.size() != 0)
						cout << ",";
				}
				cout << "]\n";
			}
		}

	}
	system("pause");
	return 0;
}