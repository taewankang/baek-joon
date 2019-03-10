#include<iostream>
#include<string.h>
#include<string>
#include<vector>
using namespace std;
int main(void) {
	string str;
	cin >> str;
	vector<int> vec(10, 0);
	for (int i = 0; i < str.length(); i++) {
		if (str[i] >= '0' && str[i] <= '9') {
			vec[str[i] - '0']++;
		}
	}
	if (vec[3] > 0 || vec[4] > 0 || vec[5] > 0 || vec[6] > 0 || vec[7] > 0 || vec[9] > 0) {	//관련 없는 수
		cout << "0\n";
	}
	else {																					//관련 있는 수
		if (vec[0] > 0 && vec[1] > 0 && vec[2] > 0 && vec[8] > 0) {						//밀접한 수
			if (vec[0] == vec[1] && vec[0] == vec[2] && vec[0] == vec[8]) {						//묶여있는 수
				cout << "8\n";
				system("pause");
				return 0;
			}
			cout << "2\n";
			system("pause");
			return 0;
		}
		cout << "1\n";
		system("pause");
		return 0;
	}
	system("pause");
	return 0;
}