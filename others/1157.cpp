#include<iostream>
#include<string.h>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
bool compare(pair<char, int> a, pair<char, int> b) {
	if (a.second < b.second)
		return true;
	else
		return false;
}
int main(void) {
	string str;
	vector<pair<char, int>> vec;
	vec.push_back(make_pair('A', 0));	vec.push_back(make_pair('B', 0));
	vec.push_back(make_pair('C', 0));	vec.push_back(make_pair('D', 0));
	vec.push_back(make_pair('E', 0));	vec.push_back(make_pair('F', 0));
	vec.push_back(make_pair('G', 0));	vec.push_back(make_pair('H', 0));
	vec.push_back(make_pair('I', 0));	vec.push_back(make_pair('J', 0));
	vec.push_back(make_pair('K', 0));	vec.push_back(make_pair('L', 0));
	vec.push_back(make_pair('M', 0));	vec.push_back(make_pair('N', 0));
	vec.push_back(make_pair('O', 0));	vec.push_back(make_pair('P', 0));
	vec.push_back(make_pair('Q', 0));	vec.push_back(make_pair('R', 0));
	vec.push_back(make_pair('S', 0));	vec.push_back(make_pair('T', 0));
	vec.push_back(make_pair('U', 0));	vec.push_back(make_pair('V', 0));
	vec.push_back(make_pair('W', 0));	vec.push_back(make_pair('X', 0));
	vec.push_back(make_pair('Y', 0));	vec.push_back(make_pair('Z', 0));
	cin >> str;
	for (int i = 0; i < str.length(); i++)
		str[i] = toupper(str[i]);
	for (int i = 0; i < str.length(); i++) {
		if (str[i] >= 'A' && str[i] <= 'Z')
			vec[(int)str[i] - 65].second++;
	}
	sort(vec.begin(), vec.end(), compare);
	if (vec[vec.size() - 1].second == vec[vec.size() - 2].second)
		cout << "?\n";
	else
		cout << vec[vec.size() - 1].first << "\n";
	system("pause");
	return 0;
}