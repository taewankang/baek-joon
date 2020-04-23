#include <iostream>
#include<unordered_map>
#include<string>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;
unordered_map<string, bool> m;
bool check(string str) {
	string s = "";
	for (int i = 0; i < str.length(); i++) {
		s += str[i];
		if (m.find(s) != m.end()) return false;
	}
	return true;
}

bool compare(string s1, string s2) {
	if (s1.length() < s2.length()) return true;
	return false;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int T, n;
	string str;
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> n;
		bool consistency = true;
		vector<string> vec(10001);
		m.clear();
		for (int i = 0; i < n; i++) {
			cin >> str;
			vec[i] = str;
		}

		sort(vec.begin(), vec.begin() + n, compare);		//�ٽ� �κ�
		//ex) 123 12345�� 12345 123�� ��� NO�� ����ؾ� �Ѵ�.
		//�׷��� ������ ���ڿ��� ���̸� ������������ ������ �ʿ䰡 �ִ�.

		for (int i = 0; i < n; i++) {
			if (check(vec[i])) 		//�ϰ����� ���ٸ�
				m.insert({ vec[i], true });
			else {
				cout << "NO\n";
				consistency = false;
				break;
			}
		}
		if (consistency) cout << "YES\n";
	}
	return 0;
}