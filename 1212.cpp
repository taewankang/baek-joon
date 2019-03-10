#include<iostream>
#include<string.h>
#include<string>
#include<algorithm>
using namespace std;
int main(void) {
	string oct;	//8진수 문자열
	cin >> oct;
	string result, dec;
	int num, n;
	bool first = false;
	for (int i = 0; i < oct.size(); i++) {
		dec = "";
		num = oct.at(i) - 48;
		if (i == 0) {
			if (oct == "0") {
				result = "0";
				break;
			}
			while (1) {
				if (num == 1) {
					n = 1;
					first = true;
				}
				else {
					n = num % 2;
					num /= 2;
				}
				dec += to_string(n);
				if (first == true)
					break;
			}
		}
		else {
			for (int j = 0; j < 3; j++) {
				dec += to_string(num % 2);
				num /= 2;
			}
		}
		reverse(dec.begin(), dec.end());			
		result += dec;
	}
	cout << result << endl;
	system("pause");
	return 0;
}