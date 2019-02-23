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
		char s;		//무슨 문자를 받을지 정함
		cin >> s;
		if (s == 'L') {
			if (iter != str_list.begin()) {	//커서를 왼쪽으로 옮김
				--iter;
			}
		}
		else if (s == 'D') {
			if (iter != str_list.end())		//커서를 오른쪽으로 옮김
				++iter;
		}
		else if (s == 'B') {				
			if (iter != str_list.begin()) {
				--iter;
			}
			else
				continue;
			iter = str_list.erase(iter);	//해당 리스트를 삭제함
		}
		else if (s == 'P') {				
			char P_char;
			cin >> P_char;
			str_list.insert(iter, P_char);	//해당 리스트를 넣는다.
		}
	}
	for (list<char>::iterator iter=str_list.begin(); iter != str_list.end(); iter++)
		cout << *iter;
	cout << endl;
	system("pause");
	return 0;
}
