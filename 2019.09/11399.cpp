#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int N, n, result = 0;
	cin >> N;
	vector<int> vec(N), ATM(N);
	for (int i = 0; i < N; i++) {
		cin >> n;
		vec[i] = n;
	}

	sort(vec.begin(), vec.end());
	ATM[0] = vec[0];
	result += vec[0];
	for (int i = 1; i < N; i++) {
		ATM[i] = ATM[i - 1] + vec[i];
		result += ATM[i];
	}
	
	cout << result << endl;
	system("pause");
	return 0;
}