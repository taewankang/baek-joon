#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;
vector<int> vec;
int maximum = 0;
void permu() {
	do {
		int sum = 0;
		for (int i = 0; i < vec.size() - 1; i++) {
			sum += abs(vec[i + 1] - vec[i]);
			maximum < sum ? maximum = sum : NULL;
		}
	} while (next_permutation(vec.begin(), vec.end()));
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int N, n;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> n;
		vec.push_back(n);
	}
	sort(vec.begin(), vec.end());
	permu();
	cout << maximum << endl;
	system("pause");
	return 0;

}