#include<iostream>
using namespace std;
int main(void) {
	int N, input, output;
	int m, maximum;
	cin >> N >> m;
	maximum = m;
	for (int i = 0; i < N; i++) {
		cin >> input >> output;
		m += input;	m -= output;
		if (maximum < m) {
			maximum = m;
		}
		if (m < 0) {
			maximum = 0;
			break;
		}
	}
	cout << maximum << endl;
	system("pause");
	return 0;
}