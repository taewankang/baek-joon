#include<iostream>
#include<vector>
using namespace std;
int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M, n;
	cin >> N >> M;
	vector<int> vec(N + 1);
	for (int i = 0; i < N; i++) {
		cin >> n;
		vec[i] = n;
	}
	int high = 0, sum = vec[0], low = 0, shortest = 987654321;

	while (high >= low && high < N) {
		if (sum >= M) {
			if (high - low + 1 < shortest) {
				shortest = high - low + 1;
			}
			sum -= vec[low++];
			if (low > high) {
				high = low;
				sum = vec[low];
			}
		}
		else if (sum < M) {
			sum += vec[++high];
		}
	}
	if (shortest == 987654321)
		shortest = 0;
	cout << shortest << endl;
	system("pause");
	return 0;
}