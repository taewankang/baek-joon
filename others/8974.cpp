#include<iostream>
#include<vector>
using namespace std;
int main(void) {
	vector<int> vec;
	vec.push_back(0);
	int A, B;
	cin >> A >> B;

	for (int i = 1; i <= 45; i++) {
		for (int j = 0; j < i; j++) {
			vec.push_back(i);
		}
	}
	long long result = 0;
	for (int i = A; i <= B; i++)
		result += vec[i];
	cout << result << "\n";
	system("pause");
	return 0;
}