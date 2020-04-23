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

		sort(vec.begin(), vec.begin() + n, compare);		//핵심 부분
		//ex) 123 12345와 12345 123은 모두 NO를 출력해야 한다.
		//그렇기 때문에 문자열의 길이를 오름차순으로 정렬할 필요가 있다.

		for (int i = 0; i < n; i++) {
			if (check(vec[i])) 		//일관성이 없다면
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