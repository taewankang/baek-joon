#include<iostream>
#include<algorithm>
using namespace std;
int main(void) {
	int L, A, B, C, D;
	int korean = 0, math = 0;
	cin >> L >> A >> B >> C >> D;
	if (A % C == 0)
		korean = A / C;
	else
		korean = A / C + 1;
	if (B % D == 0)
		math = B / D;
	else
		math = B / D + 1;
	L -= max(korean, math);
	cout << L << endl;
	system("pause");
	return 0;
}