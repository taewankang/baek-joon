#include<iostream>
#include<string>
#include<string.h>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	string str;
	cin >> str;
	int result = 0;
	for (int i = 0; i < str.length();) {
		bool remain = false;
		if (i < str.length() - 1 && str[i] == 'c') {
			if (str[i + 1] == '=' || str[i + 1] == '-') {
				remain = true;
				result++;
				i += 2;
			}
		}
		if (str[i] == 'd') {
			if (i < str.length() - 2 && str[i + 1] == 'z' && str[i + 2] == '=') {
				remain = true;
				result++;
				i += 3;
			}
			else if (i < str.length() - 1 && str[i + 1] == '-') {
				remain = true;
				result++;
				i += 2;
			}
		}
		if (i < str.length() - 1 && str[i] == 'l') {
			if (str[i + 1] == 'j') {
				remain = true;
				result++;
				i += 2;
			}
		}
		if (i < str.length() - 1 && str[i] == 'n') {
			if (str[i + 1] == 'j') {
				remain = true;
				result++;
				i += 2;
			}
		}
		if (i < str.length() - 1 && str[i] == 's') {
			if (str[i + 1] == '=') {
				remain = true;
				result++;
				i += 2;
			}
		}
		if (i < str.length() - 1 && str[i] == 'z') {
				if (str[i + 1] == '=') {
					remain = true;
					result++;
					i += 2;
			}
		}
		if(remain == false) {
			result++;
			i++;
		}
	}
	cout << result << "\n";
	system("pause");
	return 0;
}