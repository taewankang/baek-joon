#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(void) {
	int N, n;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int result = 0;
		cin >> n;
		vector<int> vec(n+1);
		fill(vec.begin(), vec.end(), 0);
		for (int j = 1; j <= n; j++) {	//¶ó¿îµå
			for (int k = 1; j*k <= n; k++) {
				if (vec[j*k] == 0)
					vec[j*k] = 1;
				else
					vec[j*k] = 0;
			}
		}
		for (int i = 0; i < vec.size(); i++) {
			if (vec[i] == 1)
				result++;
		}
		cout << result << endl;
	}
	system("pause");
	return 0;
}