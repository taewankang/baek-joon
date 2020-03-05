#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N, n;
vector<int> vec;

void permu() {
	do {
		for (int i = 0; i < N; i++)
			cout << vec[i] << " ";
		cout << "\n";
	} while (next_permutation(vec.begin(), vec.end()));
}


int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i < N; i++)
		vec.push_back(i + 1);
	permu();
	return 0;

}