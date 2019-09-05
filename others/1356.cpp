#include<iostream>
#include<vector>
using namespace std;
int main(void) {
	int N = 0, cut = 0;
	cin >> N;
	vector<int> vec;
	while (N >= 1) {		//수가 거꾸로 저장되어있는 상태
		vec.push_back(N % 10);
		N /= 10;
	}
	int f, l;
	if (vec.size() == 1)
		cout << "NO\n";
	for (int i = 1; i < vec.size(); i++) {
		f = 1;	l = 1;
		for (int j = 0; j < i; j++) {
			f *= vec[j];
		}
		for (int j = i; j < vec.size(); j++) {
			l *= vec[j];
		}
		if (f == l) {
			cout << "YES\n";
			break;
		}
		if (i == vec.size() - 1) {
			cout << "NO\n";
			break;
		}
	}
	system("pause");
	return 0;
}