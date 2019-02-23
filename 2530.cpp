#include<iostream>
using namespace std;
int main(void) {
	int hour, minute, second;
	cin >> hour >> minute >> second;
	int plus, plus_hour, plus_minute, plus_second;
	cin >> plus;
	plus_hour = plus / 3600;
	plus -= plus_hour * 3600;
	plus_minute = plus / 60;
	plus -= plus_minute * 60;
	hour += plus_hour;
	minute += plus_minute;
	second += plus;
	if (second >= 60) {
		second -= 60;
		minute += 1;
	}
	if (minute >= 60) {
		minute -= 60;
		hour += 1;
	}
	while (1) {
		if (hour > 23)
			hour -= 24;
		if (hour < 24)
			break;
	}
	cout << hour << " " << minute << " " << second << "\n";
	system("pause");
	return 0;
}