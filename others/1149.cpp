#include<iostream>
#include<vector>
#include<tuple>
#include<algorithm>
using namespace std;
int main(void) {
	int N, red, green, blue;
	cin >> N;
	vector<tuple<int, int, int>> vec(N+1);

	for (int i = 1; i <= N; i++) {
		cin >> red >> green >> blue;
		vec[i] = { red, green, blue };
	}
	for (int i = 2; i <= N; i++) {
		get<0>(vec[i]) += min(get<1>(vec[i - 1]), get<2>(vec[i - 1]));
		get<1>(vec[i]) += min(get<0>(vec[i - 1]), get<2>(vec[i - 1]));
		get<2>(vec[i]) += min(get<0>(vec[i - 1]), get<1>(vec[i - 1]));
	}
	int minimum = get<0>(vec[N]);
	if(minimum > get<1>(vec[N]))
		minimum = get<1>(vec[N]);
	if (minimum > get<2>(vec[N]))
		minimum = get<2>(vec[N]);
	cout << minimum << "\n";
	system("pause");
	return 0;
}