#include<iostream>
#include<vector>
using namespace std;
int main(void) {
	vector<int> fibo;
	fibo.push_back(0);
	fibo.push_back(1);
	fibo.push_back(1);
	int N;
	cin >> N;
	for (int i = 3; i <= N; i++) {
		fibo.push_back(fibo[i - 1] + fibo[i - 2]);
	}
	cout << fibo[N] << "\n";
	system("pause");
	return 0;
}