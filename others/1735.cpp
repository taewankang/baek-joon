#include<iostream>
#include<algorithm>
using namespace std;

int gcd(int a, int b) {
	int mod = a % b;
	while (mod > 0) {
		a = b;
		b = mod;
		mod = a % b;
	}
	return b;
}

int main(void) {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int copy_a = a;
	int copy_c = c;
	a /= gcd(a, b);
	b /= gcd(copy_a, b);
	c /= gcd(c, d);
	d /= gcd(copy_c, d);
	int down = 0, up = 0;
	down = b * d / gcd(b, d);
	up = a * (down / b) + c * (down / d);
	int copy_up = up;
	up /= gcd(up, down);
	down /= gcd(copy_up, down);
	cout << up << " " << down << endl;
	system("pause");
	return 0;
}