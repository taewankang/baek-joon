#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int map[11][11] = { 0, };
int maximum = 123456789;
void calculate(vector<int> vec) {
	int sum = 0;
	for (int i = 0; i < vec.size() - 1; i++) {
		if (map[vec[i]][vec[i + 1]] == 0)
			return;
		sum += map[vec[i]][vec[i + 1]];
	}
	if (map[vec[vec.size() - 1]][vec[0]] == 0)
		return;
	sum += map[vec[vec.size() - 1]][vec[0]];
	maximum > sum ? maximum = sum : NULL;
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int N, n;
	cin >> N;
	vector<int> vec;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> n;
			map[i][j] = n;
		}
	}

	for (int i = 0; i < N; i++)
		vec.push_back(i);

	do {
		calculate(vec);
	} while (next_permutation(vec.begin(), vec.end()));
	cout << maximum << endl;
	system("pause");
	return 0;

}