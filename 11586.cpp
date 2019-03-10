#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(void) {
	int N;
	char n;
	cin >> N;
	int mood = 0;
	vector<vector<char>> vec(N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> n;
			vec[i].push_back(n);
		}
	}
	cin >> mood;
	if (mood == 1) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++)
				cout << vec[i][j];
			cout << "\n";
		}
	}
	
	else if (mood == 2) {
		for (int i = 0; i < N; i++)
			reverse(vec[i].begin(), vec[i].end());
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++)
				cout << vec[i][j];
			cout << "\n";
		}
	}
	else if (mood == 3) {
		for (int i = N - 1; i >= 0; i--) {
			for (int j = 0; j < N; j++)
				cout << vec[i][j];
			cout << "\n";
		}
	}
	system("pause");
	return 0;
}