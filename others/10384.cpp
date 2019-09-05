#include<iostream>
#include<string.h>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main(void) {
	int T;
	cin >> T;
	cin.ignore();
	string str;
	for (int i = 0; i < T; i++) {
		getline(cin, str);
		vector<char> vec(26, 0);
		for (int j = 0; j < str.length(); j++) {
			if (str[j] >= 'a' && str[j] <= 'z') {
				vec[str[j] - 'a']++;
			}
			else if (str[j] >= 'A' && str[j] <= 'Z') {
				vec[str[j] - 'A']++;
			}
		}
		sort(vec.begin(), vec.end());
		if (vec[0] == 0)
			cout << "Case " << i + 1 << ": Not a pangram\n";
		else if (vec[0] == 1)
			cout << "Case " << i + 1 << ": Pangram!\n";
		else if (vec[0] == 2)
			cout << "Case " << i + 1 << ": Double pangram!!\n";
		else
			cout << "Case " << i + 1 << ": Triple pangram!!!\n";
	}
	system("pause");
	return 0;
}