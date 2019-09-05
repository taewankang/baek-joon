11104
#include<iostream>
#include<string>
#include<string.h>
#include<math.h>
using namespace std;
int main(void) {
	int num;
	cin >> num;
	string str;
	int result = 0;
	for (int i = 0; i < num; i++) {
		cin >> str;
		result = 0;
		for (int j = 0; j < 24; j++) {	//24개의 이진수를 입력받고 이를 10진수로 출력
			if (str.at(j) == '1') {
				result += pow(2, 23-j);
			}
		}
		cout << result << endl;
	}
	system("pause");
	return 0;
}
