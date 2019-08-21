#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;
int maximum = 0;
void diff(vector<int> vec) {
	int result = 0;
	for (int i = 0; i < vec.size() - 1; i++) {
		result += abs(vec[i] - vec[i + 1]);
	}
	if (result > maximum)
		maximum = result;
}

void cases( vector<int> vec) {
	do {
		diff(vec);
	} while (next_permutation(vec.begin(), vec.end()));
}

int main(void) {
	int N, n;
	cin >> N;
	vector<int> vec;
	for (int i = 0; i < N; i++) {
		cin >> n;
		vec.push_back(n);
	}
	sort(vec.begin(), vec.end());
	cases(vec);
	cout << maximum << "\n";
	system("pause");
	return 0;
}
