#include<iostream>
#include<vector>
using namespace std;
int main(void) {
	vector<int> vec;
	vec.push_back(0);
	vec.push_back(1);
	int N;
	cin >> N;
	for (int i = 2; i <= N; i++) {
		vec.push_back(vec[i - 1] + vec[i - 2]);
	}
	cout << vec[N]<<endl;
	system("pause");
	return 0;
}