#include<iostream>
#include<string.h>
#include<string>
#include<list>
#include<iterator>
#include<algorithm>

using namespace std;
int main(void) {
	string str;
	int num;
	cin >> str;
	list<char> str_list;
	for (int i = 0; i < str.size(); i++)
		str_list.push_back(str[i]);
	cin >> num;
	list<char>::iterator iter=str_list.end();
	for (int i = 0; i < num; i++) {
		char s;		//���� ���ڸ� ������ ����
		cin >> s;
		if (s == 'L') {
			if (iter != str_list.begin()) {	//Ŀ���� �������� �ű�
				--iter;
			}
		}
		else if (s == 'D') {
			if (iter != str_list.end())		//Ŀ���� ���������� �ű�
				++iter;
		}
		else if (s == 'B') {				
			if (iter != str_list.begin()) {
				--iter;
			}
			else
				continue;
			iter = str_list.erase(iter);	//�ش� ����Ʈ�� ������
		}
		else if (s == 'P') {				
			char P_char;
			cin >> P_char;
			str_list.insert(iter, P_char);	//�ش� ����Ʈ�� �ִ´�.
		}
	}
	for (list<char>::iterator iter=str_list.begin(); iter != str_list.end(); iter++)
		cout << *iter;
	cout << endl;
	system("pause");
	return 0;
}
