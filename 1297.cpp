#include<iostream>
#include<math.h>
using namespace std;
int main(void) {
	double a, b, c;
	cin >> a >> b >> c;
	double new_a = a * a;
	double new_b = b * b;
	double new_c = c * c;
	double rate = new_a / (new_b + new_c);
	rate = sqrt(rate);
	cout << (int)(b * rate) << " " << (int)(c * rate) << "\n";

	system("pause");
	return 0;
}