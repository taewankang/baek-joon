#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
int main(void) {
	int N;
	cin >> N;
	vector<pair<int, int>> vec(N + 1, { 0, 0 });
	vec[1] = { 1, 1 };
	vec[2] = { 2, 2 };
	for (int i = 3; i <= N; i++) {
		int min = 100000;
		vec[i].first = i;
		for (int j = 1; j <= sqrt(i); j++) {
			if (vec[i - pow(j, 2)].second < min) {
				min = vec[i- pow(j, 2)].second;;
			}
		}
		vec[i].second = min + 1;
	}
	cout << vec[N].second << "\n";
	system("pause");
	return 0;
}