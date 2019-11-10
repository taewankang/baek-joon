#include<iostream>
#include<vector>
using namespace std;
vector<int> vec(1000001);
int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int N, n;
	cin >> N;
	cin >> n;
	vec[1] = n;
	int cnt = 1;
	for (int i = 1; i < N; i++) {
		cin >> n;
		bool finding = false;
		for (int j = 1; j <= cnt; j++) {
			if (vec[j] >= n) {
				vec[j] = n;
				finding = true;
				break;
			}
		}
		if (!finding) {
			vec[cnt + 1] = n;
			cnt++;
		}
	}
	cout << cnt << endl;
	system("pause");
	return 0;
}