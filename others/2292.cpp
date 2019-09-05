#include<iostream>
using namespace std;
int main(void) {
	int N, result = 0, counting = 1;
	cin >> N;
	if (N == 1) {
		cout << "1\n";
	}
	else {
		while (1) {
			if (3 * counting*(counting - 1) + 2 > N) {
				cout << counting << endl;
				break;
			}
			counting++;
		}
	}
	system("pause");
	return 0;
}