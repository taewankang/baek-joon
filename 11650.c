11650
#include <iostream>
#include <algorithm>
#include<vector>
using namespace std;

int main()
{
	int x, y;
	vector<pair<int, int>> vec;

	int N;
	cin >> N;

	for (int i = 0; i < N; ++i) {
		scanf("%d %d", &x, &y);
		vec.push_back(make_pair(x, y));
	}

	sort(vec.begin(), vec.end());

	for (int i = 0; i < n; ++i) {
		printf("%d %d\n", vec[i].first, vec[i].second);
	}
	system("pause");
	return 0;
}