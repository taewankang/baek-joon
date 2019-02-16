#include<iostream>
using namespace std;
int main(void) {
	int N;
	cin >> N;
	int year = 2014, month = 4, day = 1;
	int pyear[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };	//365
	int yyear[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };	//366
	if (N >= 30) {
		N -= 30;			//2014년 5월 1일에서 시작
		month++;
		day = 1;
	}
	else {
		cout << "2014-04-";
		if (day + N < 10)
			cout << "0" << day + N << endl;
		else
			cout << day + N << endl;
		system("pause");
		return 0;
	}
	while (1) {
		if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {	//윤년이라면
			if (N >= yyear[month]) {
				N -= yyear[month];
				month++;
				if (month > 12) {
					year++;
					month = 1;
				}
			}
			else if (N < yyear[month]) {
				day += N;
				cout << year << "-";
				if (month < 10)
					cout << "0" << month;
				else
					cout << month;
				cout << "-";
				if (day < 10)
					cout << "0" << day << "\n";
				else
					cout << day << "\n";
				break;
			}
		}
		else {									//평년이라면
			if (N >= pyear[month]) {
				N -= pyear[month];
				month++;
				if (month > 12) {
					year++;
					month = 1;
				}
			}
			else if (N < pyear[month]) {
				day += N;
				cout << year << "-";
				if (month < 10)
					cout << "0" << month;
				else
					cout << month;
				cout << "-";
				if (day < 10)
					cout << "0" << day << "\n";
				else
					cout << day << "\n";
				break;
			}
			
		}
	}
	system("pause");
	return 0;
}