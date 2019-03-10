#include<iostream>
#include<string.h>
#include<string>
using namespace std;
int main(void) {
	int C, T;	//C는 홀수가 나왔을 때 T는 짝수가 나왔을 때
	string str="";
	while (1) {
		C = 0;	T = 0;
		getline(cin, str);
		if (str == "#")
			break;
		for (int i = 0; i < str.length(); i++) {
			if (str[i] == 'A') {
				C++;
			}
			else if (str[i] == '1' && str[i + 1] == '0') {
				T++;
				i++;
			}
			else if (str[i] - '0' >= 0 && str[i] - '0' < 10) {
				if ((str[i] - '0') % 2 == 0) {
					T++;
				}
				else
					C++;
			}
		}
		if (C > T)
			cout << "Cheryl\n";
		else if (C < T)
			cout << "Tania\n";
		else if (C == T)
			cout << "Draw\n";
 	}
	system("pause");
	return 0;
}