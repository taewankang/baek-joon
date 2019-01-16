#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(void) {
	int N;
	vector<int> vec;
	cin >> N;
	int num = 0;
	for (int i = 0; i < N; i++) {
		cin >> num;
		vec.push_back(num);
	}
	sort(vec.begin(), vec.end());
	for (int i = 0; i < vec.size(); i++)
		cout << vec[i] << "\n";
	system("pause");
	return 0;
}