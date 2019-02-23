#include<iostream>
#include<vector>
using namespace std;
int main(void) {
	int N;
	cin >> N;
	vector<long long> vec;
	vec.push_back(0);
	vec.push_back(1);
	vec.push_back(1);
	for (int i = 3; i <= N; i++) {
		vec.push_back(vec[i - 1] + vec[i - 2]);
	}
	cout << vec[N] << "\n";
	system("pause");
	return 0;
}