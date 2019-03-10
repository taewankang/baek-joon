#include<iostream>	
#include<string.h>
#include<string>
#include<vector>
using namespace std;
int main(void) {
	int T;
	cin >> T;
	for (int j = 0; j < T; j++) {
		string s, p, copy_s;
		cin >> s >> p;
		copy_s = s;
		int result = 0, i = 0;
		bool final = false;
		for (i = 0; i <= s.length() - p.length(); ) {
			if (s.substr(i, p.length()) == p) {
				s="";
				s += copy_s.substr(0, i) + copy_s.substr(i + p.length());
				copy_s = s;
				int n = s.length() - p.length();
				result++;
				if (n < 0) {
					result += s.length();
					final = true;
					break;
				}
				i = 0;
				continue;
			}
			i++;
		}
		if (final == false)
			result += s.length();
		cout << result << endl;
	}
	system("pause");
	return 0;
}