#include<iostream>
using namespace std;
int main(void) {
	int N;
	while (1) {
		cin >> N;
		if (N == 0)
			break;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= i; j++) {
				cout << "*";
			}
			cout << "\n";
		}
	}


	system("pause");
	return 0;
}