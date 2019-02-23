#include<iostream>
#include<algorithm>
#include<set>
using namespace std;
int main(void) {
	int N, n;
	cin >> N;
	set<int> s;

	for (int i = 0; i < N; i++) {
		cin >> n;
		s.insert(n);
	}
	for (set<int>::iterator itr = s.begin(); itr != s.end(); itr++) {
		cout << *itr << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}