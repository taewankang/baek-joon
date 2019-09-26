#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	vector<vector<long long>> vec(101);
	vec[1].push_back(0);
	for (int i = 1; i <= 9; i++)
		vec[1].push_back(1);

	for (int i = 2; i <= N; i++) {
		for (int j = 0; j < 10; j++) {
			if (j == 0) 
				vec[i].push_back(vec[i - 1][1] % 1000000000);
			else if (j == 9)
				vec[i].push_back(vec[i - 1][8] % 1000000000);
			else 
				vec[i].push_back((vec[i - 1][j - 1] + vec[i - 1][j + 1]) % 1000000000);
		}
	}
	long long result = 0;
	for (int i = 0; i < 10; i++)
		result += vec[N][i];
	cout << result % 1000000000 << endl;

	system("pause");
	return 0;
}