#include<iostream>
#include<vector>
using namespace std;
int main(void) {
	int N;
	cin >> N;
	int west, east;
	for (int i = 0; i < N; i++) {
		cin >> west >> east;
		vector<long long> vec(west + 1);
		vec[0]=0;
		vec[1]=east;
		for (int j = 2; j <= west; j++) {
			vec[j] = vec[j - 1] * (east - j + 1) / j;
		}
		cout << vec[west] << endl;
	}
	system("pause");
	return 0;
}