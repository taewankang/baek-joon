#include<iostream>
#include<vector>
using namespace std;
int N, K;
int era(vector<int> &vec) {
	int i = 0;
	while (i != K) {
		for (int j = 2; j <= N; j++) {
			for (int k = 1; j*k <= N; k++) {
				if (vec[j*k] != -1) {
					i++;
					if (i == K)
						return vec[j*k];
					vec[j*k] = -1;
				}
			}
		}
	}
}

int main(void) {
	cin >> N >> K;
	vector<int> vec;
	vec.push_back(0);
	vec.push_back(1);
	for (int i = 2; i <= N; i++) {
		vec.push_back(i);
	}
	cout << era(vec) << endl;
	system("pause");
	return 0;
}