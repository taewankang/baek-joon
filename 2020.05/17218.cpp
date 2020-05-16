#include<iostream>
#include<vector>
#include<string>
#include<string.h>
#include<algorithm>
#include<set>
using namespace std;
vector<vector<vector<string>>> vec;

bool compare(string s1, string s2) {
	if (s1.length() > s2.length())
		return true;
	return false;
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	string s1, s2;
	cin >> s1 >> s2;
	vec.assign(s1.length() + 1, vector<vector<string>>(s2.length() + 1, vector<string>(1)));
	for (int i = 1; i <= s1.length(); i++) {
		for (int j = 1; j <= s2.length(); j++) {
			set<string> s;
			int len = 0;
			if (s1[i - 1] == s2[j - 1])
			{
				for (auto k : vec[i - 1][j - 1]) {
					string str = k + s1[i - 1];
					if (len <= str.length()) {
						s.insert(str);
						len = str.length();
					}
				}
			}
			for (auto k : vec[i - 1][j]) {
				if (len <= k.length()) {
					s.insert(k);
					len = k.length();
				}
			}
			for (auto k : vec[i][j - 1]) {
				if (len <= k.length()) {
					s.insert(k);
					len = k.length();
				}
			}
			set<string>::iterator iter = s.begin();
			for (auto iter : s) {
				vec[i][j].push_back(iter);
			}
		}
	}
	sort(vec[s1.length()][s2.length()].begin(), vec[s1.length()][s2.length()].end(), compare);
	cout << vec[s1.length()][s2.length()][0] << endl;
	return 0;
}
