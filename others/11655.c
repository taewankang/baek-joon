11655
#include <iostream>
#include<string>
#include<string.h>
using namespace std;
int main() {
	string str;
	getline(cin, str);
	for (int i = 0; i < str.length(); i++) {
		if ((str.at(i) >= 'a' && str.at(i) <= 'z') || (str.at(i) >= 'A' && str.at(i) <= 'Z'))
			if ((str.at(i) >= 78 && str.at(i) <= 90) || (str.at(i) >= 110 && str.at(i) <= 122))	//13�� ������ �� 'a'Ȥ�� 'A'�� �Ѿ�°� �׷��� ������
				str.at(i) -= 13;
			else
				str.at(i) += 13;
		}
	cout << str << endl;
	system("pause");
	return 0;
}
