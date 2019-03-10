#include<iostream>
#include<vector>
using namespace std;
int main(void) {
	int N, n, result = 0;
	cin >> N;
	vector<int> vec;
	for (int i = 0; i < N; i++) {
		cin >> n;
		vec.push_back(n);
	}
	if (N == 1) {
		cout << "0\n";
		return 0;
	}
	for (int i = vec.size() - 1; i >= 1; i--) {
		if (vec[i] <= vec[i - 1]) {
			result += vec[i - 1] - vec[i] + 1;
			vec[i - 1] = vec[i] - 1;
		}
	}
	cout << result << endl;
	system("pause");
	return 0;
}