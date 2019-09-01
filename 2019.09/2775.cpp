#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> vec(15);

void make_apt() {
	for (int i = 0; i < 15; i++)
		vec[0].push_back(i);
	for (int i = 1; i < 15; i++) {
		for (int j = 0; j < 15; j++) {
			int sum = 0;
			for (int k = 1; k <= j; k++)
				sum += vec[i - 1][k];
			vec[i].push_back(sum);
		}
	}
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	make_apt();
	for (int t = 0; t < T; t++) {
		int k, n;
		cin >> k >> n;
		cout << vec[k][n] << "\n";
	}
	system("pause");
	return 0;
}