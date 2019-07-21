#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
#include<string>
using namespace std;
vector<char> vec;
vector<string> str;
int L, C;

void dfs(int counting, vector<char> v, int index) {
	if (counting == C) {
		if (v.size() == L) {
			int ja_count = 0, mo_count = 0;
			for (int i = 0; i < v.size(); i++) {
				if (v[i] == 'a' || v[i] == 'e' || v[i] == 'i' || v[i] == 'o' || v[i] == 'u')
					mo_count++;
				else
					ja_count++;
			}
			if (mo_count < 1 || ja_count < 2)
				return;
			else {
				string s = "";
				for (int i = 0; i < v.size(); i++)
					s += v[i];
				str.push_back(s);
			}
		}
		return;
	}
	dfs(counting + 1, v, index + 1);
	v.push_back(vec[index + 1]);
	dfs(counting + 1, v, index + 1);
}

int main(void) {
	char n;
	cin >> L >> C;
	vector<char> v;
	for (int i = 0; i < C; i++) {
		cin >> n;
		vec.push_back(n);
	}
	sort(vec.begin(), vec.end());
	dfs(0, v, -1);
	reverse(str.begin(), str.end());
	for (int i = 0; i < str.size(); i++)
		cout << str[i] << "\n";
	system("pause");
	return 0;
}