#include<iostream>
#include<string.h>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main(void) {
	string A, B;
	cin >> A >> B;
	vector<int> vec_A(81), vec_B(81);
	vector<int> result(81, 0);
	int j = 80;
	for (int i = A.length() - 1; i >= 0; i--) {
		vec_A[j] = A[i] - '0';
		j--;
	}
	j = 80;
	for (int i = B.length() - 1; i >= 0; i--) {
		vec_B[j] = B[i] - '0';
		j--;
	}
	for (int i = 80; i > 0; i--) {
		result[i] += vec_A[i] + vec_B[i];
		if (result[i] > 1) {
			result[i] -= 2;
			result[i - 1]++;
		}
	}
	vector<int>::iterator itr=result.begin();
	itr=find(result.begin(), result.end(), 1);
	if (itr == result.end())
		cout << "0";
	for (; itr != result.end(); itr++)
		cout << *itr;
	cout << endl;
	system("pause");
	return 0;
}