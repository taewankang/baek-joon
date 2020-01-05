/*
	1. 입력은 여러줄일 수 있기 때문에 while(getline(cin, str)){}을 사용함
*/
#include<iostream>
#include<string>
#include<string.h>
#include<vector>
using namespace std;

vector<char> make_small_mo() {
	vector<char> vec;
	string str = "aiyeou";
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < str.length(); j++)
			vec.push_back(str[j]);
	return vec;
}

vector<char> make_small_ja() {
	string str = "bkxznhdcwgpvjqtsrlmf";
	vector<char> vec;
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < str.length(); j++)
			vec.push_back(str[j]);
	return vec;
}

vector<char> make_big_ja() {
	string str = "BKXZNHDCWGPVJQTSRLMF";
	vector<char> vec;
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < str.length(); j++)
			vec.push_back(str[j]);
	return vec;
}

vector<char> make_big_mo() {
	vector<char> vec;
	string str = "AIYEOU";
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < str.length(); j++)
			vec.push_back(str[j]);
	return vec;
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	string str, result = "";
	vector<char> mo, ja, Mo, Ja;
	mo = make_small_mo();
	ja = make_small_ja();
	Mo = make_big_mo();
	Ja = make_big_ja();
	while (getline(cin, str)) {
		result = "";
		for (int i = 0; i < str.length(); i++) {
			if (str[i] >= 'a' && str[i] <= 'z') {
				if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'y' || str[i] == 'o' || str[i] == 'u') {
					for (int j = 0; j < mo.size(); j++) {
						if (mo[j] == str[i]) {
							result += mo[j + 3];
							break;
						}
					}
				}
				else {
					for (int j = 0; j < ja.size(); j++) {
						if (ja[j] == str[i]) {
							result += ja[j + 10];
							break;
						}
					}
				}
			}
			else if (str[i] >= 'A' && str[i] <= 'Z') {
				if (str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'Y' || str[i] == 'O' || str[i] == 'U') {
					for (int j = 0; j < Mo.size(); j++)
						if (Mo[j] == str[i]) {
							result += Mo[j + 3];
							break;
						}
				}
				else {
					for (int j = 0; j < Ja.size(); j++)
						if (Ja[j] == str[i]) {
							result += Ja[j + 10];
							break;
						}
				}
			}
			else
				result += str[i];
		}
		cout << result << endl;
	}
	system("pause");
	return 0;
}