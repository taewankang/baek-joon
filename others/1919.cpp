#include<iostream>
#include<vector>
#include<string.h>
#include<string>
using namespace std;
int main(void) {
	string str1, str2;
	cin >> str1 >> str2;
	int result = 0;
	vector<pair<char, int>> s1, s2;

	for (int i = 0; i < str1.length(); i++) 
		s1.push_back({ str1[i], 0 });
	for (int i = 0; i < str2.length(); i++) 
		s2.push_back({ str2[i], 0 });

	for (int i = 0; i < s1.size(); i++) {
		for (int j = 0; j < s2.size(); j++) {
			if (s1[i].second == -1)
				break;
			if (s2[j].second == -1) {
				continue;
			}
			if (s1[i].first == s2[j].first) {
				s1[i].second = -1;
				s2[j].second = -1;
				break;
			}
		}
	}
	for (int i = 0; i < s1.size(); i++)
		if (s1[i].second != -1)
			result++;

	for (int i = 0; i < s2.size(); i++)
		if (s2[i].second != -1)
			result++;
	cout << result << "\n";

	system("pause");
	return 0;
}