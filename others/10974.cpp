#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(void) {
	int N;
	cin >> N;
	vector<int> vec;

	for (int i = 1; i <= N; i++) {
		vec.push_back(i);
		cout << vec[i - 1] << " ";
	}
	cout << "\n";
	while (next_permutation(vec.begin(), vec.end())) {
		for (int i = 0; i < vec.size(); i++)
			cout << vec[i] << " ";
		cout << "\n";
	}
	system("pause");
	return 0;
}