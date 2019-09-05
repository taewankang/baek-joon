#include<iostream>
#include<string.h>
#include<string>
#include<algorithm>
using namespace std;
int main(void) {
	string str;			
	cin >> str;
	string result;
	bool finish = false;
	int oct;			//8진수로 변환할 변수

	for (int i = str.length() - 1; i >= 0; ) {
		if (i > 2) {
			oct = ((str.at(i)-48) + (str.at(i - 1)-48) * 2 + (str.at(i - 2)-48) * 4);
			i -= 3;
		}
		else if (i == 2) {
			oct = ((str.at(i) - 48) + (str.at(i - 1) - 48) * 2 + (str.at(i - 2) - 48) * 4);
			finish = true;
		}
		else if (i == 1) {
			oct = ((str.at(i)-48) + (str.at(i - 1)-48) * 2);
			finish = true;
		}
		else if (i == 0) {
			oct = (str.at(i)-48);
			finish = true;
		}
		result += to_string(oct);
		if (finish == true)
			break;
	}
	reverse(result.begin(), result.end());
	cout << result << endl;

	system("pause");
	return 0;