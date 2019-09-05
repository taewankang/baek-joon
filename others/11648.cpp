#include<iostream>
using namespace std;
int main(void) {
	int result = 0, num;
	cin >> num;
	int new_num = 1;
	while (num >= 10) {
		new_num = 1;
		while (num>=1) {
			new_num *= num % 10;
			num /= 10;
		}
		result++;
		num = new_num;
	}
	cout << result << endl;
	system("pause");
	return 0;
}