4593
#include<iostream>
#include<string.h>
#include<string>
using namespace std;
int main(void) {
	string player1;
	string player2;
	while (1) {
		int p1_win = 0;
		int p2_win = 0;
		getline(cin, player1);
		getline(cin, player2);
		if (player1 == "E" && player2 == "E")
			break;
		for (int i = 0; i < player1.size(); i++) {
			if (player1.at(i) == 'R' && player2.at(i) == 'S')	//승자에 해당하는 변수를 1증가시킨다.
				p1_win++;
			else if (player1.at(i) == 'R' && player2.at(i) == 'P')
				p2_win++;
			else if (player1.at(i) == 'S' && player2.at(i) == 'R')
				p2_win++;
			else if (player1.at(i) == 'S' && player2.at(i) == 'P')
				p1_win++;
			else if (player1.at(i) == 'P' && player2.at(i) == 'R')
				p1_win++;
			else if (player1.at(i) == 'P' && player2.at(i) == 'S')
				p2_win++;
		}
		cout << "P1: " << p1_win << endl;
		cout << "P2: " << p2_win << endl;
	}
	system("pause");
	return 0;

