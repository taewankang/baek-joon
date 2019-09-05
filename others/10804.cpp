#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(void) {
	vector<int> vec;
	vec.push_back(0);
	int a, b;;
	for (int i = 1; i <= 20; i++)
		vec.push_back(i);
	for (int i = 0; i < 10; i++) {
		cin >> a >> b;
		reverse(vec.begin() + a, vec.begin() + b + 1);	
	}

	for (int i = 1; i < 21; i++)
		cout << vec[i] << " ";
	cout << endl;
	system("pause");
	return 0;
}