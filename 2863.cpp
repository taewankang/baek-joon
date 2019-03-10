#include<iostream>
#include<algorithm>
using namespace std;
int main(void) {
	int A, B, C, D;
	cin >> A >> B >> C >> D;
	double first = double(A * D + B * C) / (C * D);
	double second = double(C * B + A * D) / (B * D);
	double third = double(D * A + B * C) / (A * B);
	double fourth = double(B * C + A * D) / (A * C);
	double result = max(max(first, second), max(third, fourth));
	if (result == first)
		cout << "0\n";
	else if (result == second)
		cout << "1\n";
	else if (result == third)
		cout << "2\n";
	else if (result == fourth)
		cout << "3\n";
	system("pause");
	return 0;
}