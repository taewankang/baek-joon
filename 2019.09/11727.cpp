#include<iostream>
#include<vector>
using namespace std;
int N;
int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> N;
	vector<int> vec(N+1);
	vec[1] = 1;
	vec[2] = 3;
	for (int i = 3; i <= N; i++) {
		vec[i] = vec[i - 2] * 2 + vec[i - 1];
		vec[i] %= 10007;
	}
	cout << vec[N] << endl;
	system("pause");
	return 0;
}