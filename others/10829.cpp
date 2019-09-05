#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(void) {
	long long N;
	cin >> N;
	vector<int> vec;
	while (N >= 1) {
		vec.push_back(N % 2);
		N /= 2;
	}
	reverse(vec.begin(), vec.end());
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i];
	}
	cout << "\n";
	system("pause");
	return 0;
}