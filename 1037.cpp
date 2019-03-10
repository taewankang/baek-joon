#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(void) {
	int N;
	long long n;
	cin >> N;
	vector<long long> vec;
	for (int i = 0; i < N; i++) {
		cin >> n;
		vec.push_back(n);
	}
	sort(vec.begin(), vec.end());
	long long result = vec[0] * vec[vec.size() - 1];
	cout << result << endl;
	system("pause");
	return 0;
}