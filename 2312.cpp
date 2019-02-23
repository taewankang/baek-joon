#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> soinsu(int N) {
	vector<vector<int>> vec(N+1);
	while (N > 1) {
		for (int i = 2; i <= N; i++) {
			if (N % i == 0) {
				N /= i;
				if (vec[i].size() == 0)
					vec[i].push_back(1);
				else
					vec[i][0]++;
				break;
			}
		}
	}
	return vec;
}

int main(void) {
	int T, N;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N;
		vector<vector<int>> vec=soinsu(N);
		for (int j = 2; j <= N; j++) {
			if (vec[j].size() != 0) {
				cout << j << " " << vec[j][0] << "\n";
			}
		}
	}
	system("pause");
	return 0;
}