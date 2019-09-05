#include<iostream>
#include<vector>
using namespace std;
int main(void) {
	int N, n, max = 0;
	cin >> N;

	vector<int> vec;
	for (int i = 0; i < N; i++) {
		cin >> n;
		vec.push_back(n);
	}
	int lowest = vec[0];
	int highest = 0;
	for (int i = 0; i < N - 1; i++) {
		if (vec[i] > vec[i + 1]) {
			if(max < highest - lowest)
				max = highest - lowest;
			lowest =  vec[i + 1];
			highest = 0;
		}
		else if (vec[i] < vec[i + 1]) {
			highest = vec[i + 1];
		}
		else if (vec[i] == vec[i + 1]) {
			lowest = vec[i];
			highest = 0;
		}
	}
	if (max < highest - lowest)
		max = highest - lowest;
	cout << max << endl;
	system("pause");
	return 0;
}