#include<iostream>
#include<vector>
#include<string>
#include<string.h>
#include<algorithm>
using namespace std;
int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	string str1, str2;
	cin >> str1 >> str2;
	vector<vector<int>> vec(str2.length() + 1);

	for (int i = 0; i < str1.length(); i++) 
		vec[0].push_back(0);

	for (int i = 1; i <= str2.length(); i++) {
		for (int j = 0; j < str1.length(); j++) {
			if (str1[j] == str2[i - 1]) {
				if (j > 0)
					vec[i].push_back(vec[i - 1][j - 1] + 1);
				else
					vec[i].push_back(1);
			}
			else {
				if (j > 0 && i > 0)
					vec[i].push_back(max(vec[i - 1][j], vec[i][j - 1]));
				else if (i > 0)
					vec[i].push_back(vec[i - 1][j]);
			}
		}
	}
	cout << vec[str2.length()][str1.length() - 1] << endl;
	system("pause");
	return 0;
}