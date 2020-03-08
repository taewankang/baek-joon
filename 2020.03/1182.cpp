#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N, S, result = 0;
vector<int> vec;
bool check[21] = { false, };

void permu(int idx, int cnt, int depth) {
	if (cnt == depth) {
		int arr[21] = { 0, };
		int sum = 0;
		for (int i = 0; i < N; i++) {
			if (check[i] == true) {
				sum += vec[i];
			}
		}
		if (sum == S)
			result++;
		return;
	}

	for (int i = idx; i < N; i++) {
		if (check[i] == true)	continue;
		check[i] = true;
		permu(i, cnt + 1, depth);
		check[i] = false;
	}
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	cin >> N >> S;
	for (int i = 0; i < N; i++) {
		cin >> n;
		vec.push_back(n);
	}

	for (int i = 1; i <= N; i++) {
		permu(0, 0, i);
	}

	cout << result << endl;

	system("pause");
	return 0;

}