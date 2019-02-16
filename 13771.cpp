#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(void) {
	int N;
	cin >> N;
	double money;
	vector<double> vec;
	for (int i = 0; i < N; i++) {
		cout.precision(2);
		cout<<fixed;
		cin >> money;
		vec.push_back(money);
	}
	sort(vec.begin(), vec.end());
	cout << vec[1] << "\n";
	system("pause");
	return 0;
}