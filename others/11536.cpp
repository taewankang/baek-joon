#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
#include<string>
using namespace std;
bool increasing(string a, string b) {
	if (a < b)
		return true;
	else
		return false;
}

bool decreasing(string a, string b) {
	if (a > b)
		return true;
	else
		return false;
}
int main(void) {
	int N;
	cin >> N;
	vector<string> vec;
	string str;
	int inc = 0, dec = 0;
	for (int i = 0; i < N; i++) {
		cin >> str;
		vec.push_back(str);
	}
	vector<string> increase(vec);
	vector<string> decrease(vec);
	sort(increase.begin(), increase.end(), increasing);
	sort(decrease.begin(), decrease.end(), decreasing);

	for (int i = 0; i < vec.size(); i++) {
		if (increase[i] == vec[i])
			inc++;
		if (decrease[i] == vec[i])
			dec++;
	}
	if (inc == vec.size())
		cout << "INCREASING\n";
	else if (dec == vec.size())
		cout << "DECREASING\n";
	else
		cout << "NEITHER\n";
	system("pause");
	return 0;
}