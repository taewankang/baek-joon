#include<iostream>
#include<string>
#include<stack>
#include<algorithm>
using namespace std;
int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	string str1, str2;
	cin >> str1 >> str2;
	stack<char> s;

	for (int i = 0; i < str1.length(); i++) {
		if (str1[i] == str2[str2.length() - 1] && s.size() >= str2.length() - 1) {
			string str = "";
			str += str2[str2.length() - 1];
			for (int j = 0; j < str2.length() - 1; j++) {
				str += s.top();
				s.pop();
			}
			reverse(str.begin(), str.end());
			if (str != str2) {
				for (int j = 0; j < str.length(); j++)
					s.push(str[j]);
			}
		}
		else
			s.push(str1[i]);
	}
	string result = "";
	while (!s.empty()) {
		result += s.top();
		s.pop();
	}
	reverse(result.begin(), result.end());
	if (result == "")
		result = "FRULA";
	cout << result << endl;
	return 0;
}
