#include<iostream>
#include<vector>
using namespace std;
int vec[10001][102] = { 0, };
vector<int> input;
int N, k, n;
int minimum = 10002, min_index = 0;

void dp(int num) {
	bool start = true;
	for (int i = 1; i <= N; i++) {
		if (num - input[i] < 0)
			continue;
		if (vec[num - input[i]][0] + input[i] == num) {
			if (start == true) {
				vec[num][101] = vec[num - input[i]][101] + 1;
				vec[num][0] = num;
				start = false;
			}
			if (vec[num - input[i]][101] + 1 < vec[num][101]) {
				for (int j = 1; j <= N; j++) {
					vec[num][j] = vec[num - input[i]][j];
				}
				vec[num][i] += 1;
				vec[num][101] = vec[num - input[i]][101] + 1;
			}
		}
	}
}


int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> k;
	input.push_back(0);
	for (int i = 1; i <= N; i++) {
		cin >> n;
		if (n < minimum) {
			minimum = n;
			min_index = i;
		}
		input.push_back(n);
	}

	vec[minimum][min_index] = 1;
	vec[minimum][0] = minimum;
	vec[minimum][101] = 1;
	for (int i = minimum; i <= k; i++) 
		dp(i);

	if (vec[k][101] != 0) {
		cout << vec[k][101] << endl;
		system("pause");
		return 0;
	}
	cout << "-1" << endl;
	system("pause");
	return 0;
}