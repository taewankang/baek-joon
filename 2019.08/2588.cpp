#include<iostream>
#include<vector>
using namespace std;
int main(void) {
	int A, B, copy_B;
	cin >> A >> B;
	copy_B = B;
	vector<int> vec;
	while (B > 0) {
		vec.push_back(B % 10);
		B /= 10;
	}
	vector<int> result;
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] * A << "\n";
	}
	cout << A * copy_B << "\n";
	system("pause");
	return 0;
}
