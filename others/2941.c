2941
#include<iostream>
#include<string.h>
#include<string>
using namespace std;
int main(void) {
	string str;
	int result = 0;
	bool wrong_pass=false;
	getline(cin, str);
	for (int i = 0; i < str.length(); i++) {
		if (i < (str.length() - 2)) {		문자열의 끝에서 2번째 문자전까지 실행
			if (str.at(i) == 'c' && (str.at(i + 1) == '=' || str.at(i + 1) == '-')) {	//현재 문자와 다음 문자까지 체크
				result++;
				i += 1;
			}
			else if (str.at(i) == 'd' && str.at(i + 1) == 'z' && str.at(i + 2) == '=') {
				result++;
				i += 2;
			}
			else if (str.at(i) == 'd' && str.at(i + 1) == '-') {
				result++;
				i += 1;
			}
			else if (str.at(i) == 'l' && str.at(i + 1) == 'j') {
				result++;
				i += 1;
			}
			else if (str.at(i) == 'n' && str.at(i + 1) == 'j') {
				result++;
				i += 1;
			}
			else if (str.at(i) == 's' && str.at(i + 1) == '=') {
				result++;
				i++;
			}
			else if (str.at(i) == 'z' && str.at(i + 1) == '=') {
				result++;
				i++;
			}
			else
				result++;
		}
		else if (i == (str.length() - 2)) {		//문자열의 뒤에서 2번째 문자일 때 실행
			if (str.at(i) == 'c' && (str.at(i + 1) == '=' || str.at(i + 1) == '-')) {
				result++;
				i += 1;
				wrong_pass = true;		
			}
			else if (str.at(i) == 'd' && str.at(i + 1) == '-') {
				result++;
				i += 1;
				wrong_pass = true;
			}
			else if (str.at(i) == 'l' && str.at(i + 1) == 'j') {
				result++;
				i += 1;
				wrong_pass = true;
			}
			else if (str.at(i) == 'n' && str.at(i + 1) == 'j') {
				result++;
				i += 1;
				wrong_pass = true;
			}
			else if (str.at(i) == 's' && str.at(i + 1) == '=') {
				result++;
				i++;
				wrong_pass = true;
			}
			else if (str.at(i) == 'z' && str.at(i + 1) == '=') {
				result++;
				i++;
				wrong_pass = true;
			}
			else
				result++;
		}
		if (i == str.length() - 1) {		//문자열의 마지막 문자일 때 실행
			if (wrong_pass == false)		//가장 마지막 문자가 크로아티아 알파벳이 아닐 경우
				result++;
			break;
		}
	}
	cout << result << endl;
	system("pause");
	return 0;
}