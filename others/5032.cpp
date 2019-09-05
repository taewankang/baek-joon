#include<iostream>
using namespace std;
int result = 0;
void recursive(int num, int c, int left) {
	result += num / c;
	if (left + num / c < c)
		return;
	else {
		recursive(num / c + left, c, (num/c + left)%c);
	}
}
int main(void) {
	int e, f, c;
	cin >> e >> f >> c;
	int sum = e + f;
	recursive(sum, c, sum%c);
	cout << result << endl;
	system("pause");
	return 0;
}