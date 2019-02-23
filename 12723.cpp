#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool compare(long long a, long long b) {
	if (a > b)
		return true;
	else
		return false;
}
int main(void) {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int N, n;
		cin >> N;
		vector<int> v1, v2;
		long long result = 0;
		for (int j = 0; j < N; j++) {
			cin >> n;
			v1.push_back(n);
		}
		for (int j = 0; j < N; j++) {
			cin >> n;
			v2.push_back(n);
		}
		sort(v1.begin(), v1.end());
		sort(v2.begin(), v2.end(), compare);
		for (int i = 0; i < N; i++) {
			result += v1[i] * v2[i];
		}
		cout << "Case #"<< i + 1 <<": " << result << "\n";
	}
	system("pause");
	return 0;
}