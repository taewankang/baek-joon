#include<iostream>
#include<vector>
using namespace std;
int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int N, n, maximum = 0;
	cin >> N;
	vector<int> vec(N), front(N, 1), back(N, 1), mid(N, 0);
	for (int i = 0; i < N; i++) {
		cin >> n;
		vec[i] = n;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < i; j++) {
			if (vec[i] > vec[j] && front[i] < front[j] + 1) {
				front[i]++;
			}
		}
	}

	for (int i = N - 1; i >= 0; i--) {
		for (int j = N - 1; j > i; j--) {
			if (vec[i] > vec[j] && back[i] < back[j] + 1) {
				back[i]++;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		if (front[i] + back[i] > maximum)
			maximum = front[i] + back[i];
	}

	cout << maximum - 1<< endl;
	system("pause");
	return 0;
}