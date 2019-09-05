#include<iostream>
#include<vector>
using namespace std;
int main(void) {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int result = 0;
		vector<int> vec(10);
		long long number;
		cin >> number;
		while (number >= 1) {
			vec[number % 10]++;
			number /= 10;
		}
		for (int j = 0; j < 10; j++) {
			if (vec[j] >= 1)
				result++;
		}
		cout << result << "\n";
	}
	system("pause");
	return 0;
}