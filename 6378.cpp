#include<iostream>
#include<vector>
#include<string.h>
#include<string>
using namespace std;
int main(void) {
	string N;

	while (1) {
		cin >> N;
		if (N == "0")
			break;
		vector<int> vec;
		int sum = 0;
		for (int i = 0; i < N.length(); i++) {
			vec.push_back(N[i] - 48);
			sum += vec[i];
		}
		if (sum < 10)
			cout << sum << "\n";
		else {
			while (1) {
				int result = 0;
				while (sum >= 10) {
					result += sum / 10;
					sum %= 10;
				}
				result += sum;
				if (result < 10) {
					cout << result << "\n";
					break;
				}
				else
					sum = result;
			}
		}
	}
	system("pause");
	return 0;
}