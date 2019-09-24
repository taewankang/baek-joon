#include<iostream>
#include<vector>
using namespace std;
int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int N, n, max = 0;
	cin >> N;
	vector<int> vec, result;
	for (int i = 0; i < N; i++) {
		cin >> n;
		vec.push_back(n);
	}
	for (int i = 0; i < N; i++) {
		result.push_back(1);
		for (int j = 0; j < i; j++) {
			if (vec[i] > vec[j] && result[i] < result[j] + 1)
				result[i]++;
		}
		cout << result[i] << " ";
		if (max < result[i])
			max = result[i];
	}
	cout << N - max << endl;

	system("pause");
	return 0;
}