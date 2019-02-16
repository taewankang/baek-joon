#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool compare(int a, int b) {
	if (a > b)
		return true;
	else
		return false;
}
int main(void) {
	int n, m, day = 1;
	cin >> n;
	vector<int> vec;
	for (int i = 0; i < n; i++) {
		cin >> m;
		vec.push_back(m+1);
	}

	sort(vec.begin(), vec.end(), compare);
	for (int i = 0; i < vec.size(); i++) {
		vec[i] = vec[i] - vec.size() + i;
	}
	day = vec.size();
	sort(vec.begin(), vec.end());
	day += vec[vec.size() - 1] + 1; 
	cout << day << endl;
	system("pause");
	return 0;
}