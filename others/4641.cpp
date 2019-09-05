#include<iostream>
#include<string.h>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main(void) {
	string str;
	while (1) {
		getline(cin, str);
		int num = 0, result = 0;
		vector<int> vec, save(200, 0);

		if (str == "-1")
			break;
		for (int i = 0; i < str.length(); i++) {
			if (str[i] >= '0' && str[i] <= '9') {
				num *= 10;
				num += str[i] - '0';
			}
			else if (str[i] == ' ') {
				vec.push_back(num);
				save[num]++;
				num = 0;
			}
		}
		sort(vec.begin(), vec.end());
		for (int i = 0; i < vec.size(); i++) {
			if (save[vec[i] * 2] > 0)
				result++;
		}
		cout << result << endl;
	}
	system("pause");
	return 0;
}