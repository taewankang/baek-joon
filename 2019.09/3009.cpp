#include<iostream>
#include<vector>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	vector<pair<int, int>> vec;
	int x, y;
	for (int i = 0; i < 3; i++) {
		cin >> x >> y; 
		vec.push_back({x, y});
	}
	if (vec[0].first == vec[1].first)
		cout << vec[2].first << " ";
	else if (vec[0].first == vec[2].first)
		cout << vec[1].first << " ";
	else
		cout << vec[0].first << " ";
	if (vec[0].second == vec[1].second)
		cout << vec[2].second << "\n";
	else if (vec[0].second == vec[2].second)
		cout << vec[1].second << "\n";
	else
		cout << vec[0].second << "\n";
	system("pause");
	return 0;
}