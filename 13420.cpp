#include<iostream>
using namespace std;
int main(void) {
	int T;
	cin >> T;
	long long a, b, r;
	char c, eq;
	long long result = 0;
	for (int k = 0; k < T; k++) {
		cin >> a >> c >> b>>eq>>r;
		if (c == '+')
			result = a + b;
		else if (c == '-')
			result = a - b;
		else if (c == '*')
			result = a * b;
		else if (c == '/')
			result = a / b;
		if (result == r)
			cout << "correct\n";
		else
			cout << "wrong answer\n";
	}
	system("pause");
	return 0;
}