#include<iostream>
#include<vector>
using namespace std;
int N, M, n, nearest;
bool check[101] = { 0, };
vector<int> vec;
void combination(int start, int depth) {
	if (depth == 3) {
		int sum = 0;
		for (int i = 1; i <= N; i++) {
			if (check[i] == true)
				sum += vec[i];
		}
		if (M - sum >= 0 && M - sum < M - nearest)
			nearest = sum;
		return;
	}
	for (int i = start; i <= N; i++) {
		check[i] = true;
		combination(i + 1, depth + 1);
		check[i] = false;
	}
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> N >> M;
	vec.push_back(0);
	for (int i = 0; i < N; i++) {
		cin >> n;
		vec.push_back(n);
	}
	combination(1, 0);
	cout << nearest << endl;
	system("pause");
	return 0;
}