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
		if (i < (str.length() - 2)) {		���ڿ��� ������ 2��° ���������� ����
			if (str.at(i) == 'c' && (str.at(i + 1) == '=' || str.at(i + 1) == '-')) {	//���� ���ڿ� ���� ���ڱ��� üũ
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
		else if (i == (str.length() - 2)) {		//���ڿ��� �ڿ��� 2��° ������ �� ����
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
		if (i == str.length() - 1) {		//���ڿ��� ������ ������ �� ����
			if (wrong_pass == false)		//���� ������ ���ڰ� ũ�ξ�Ƽ�� ���ĺ��� �ƴ� ���
				result++;
			break;
		}
	}
	cout << result << endl;
	system("pause");
	return 0;
}