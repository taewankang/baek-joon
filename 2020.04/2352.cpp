#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int N, n;
	cin >> N;
	vector<int> vec(N + 1), temp;
	for (int i = 0; i < N; i++) {
		cin >> n;
		vec[i] = n;
	}


	for (int i = 0; i < N; i++) {
		int idx = lower_bound(temp.begin(), temp.end(), vec[i]) - temp.begin();
		if (idx == temp.size())
			temp.push_back(vec[i]);
		else
			temp[idx] = vec[i];
	}
	cout << temp.size() << endl;
	system("pause");
	return 0;
}