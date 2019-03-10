#include<iostream>
#include<string.h>
#include<string>
#include<vector>
using namespace std;
int main(void) {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int n;
		string jenga;
		cin >> n;
		bool fallen = false;
		vector<string> str;
		for (int j = 0; j < n; j++) {
			cin >> jenga;
			str.push_back(jenga);
		}
		for (int j = 0; j < n; j++) {
			if (str[j] == "100" || str[j] == "001" || str[j] == "000") {
				fallen = true;
				break;
			}
		}
		if (fallen == true) 
				cout << "Case " << i + 1 << ": Fallen\n";
		else
			cout << "Case " << i + 1 << ": Standing\n";
	}
	system("pause");
	return 0;
}