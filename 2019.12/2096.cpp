#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N;
vector<int> small(4), big(4);
int n1, n2, n3;

void smallest(vector<int>& vec) {
	n1 = min(small[1], small[2]) + vec[1];
	n2 = min(small[1], min(small[2], small[3])) + vec[2];
	n3 = min(small[2], small[3]) + vec[3];
	small[1] = n1; small[2] = n2; small[3] = n3;
}

void biggest(vector<int>& vec) {
	n1 = max(big[1], big[2]) + vec[1];
	n2 = max(big[1], max(big[2], big[3])) + vec[2];
	n3 = max(big[2], big[3]) + vec[3];
	big[1] = n1; big[2] = n2; big[3] = n3;
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	cin >> N;
	vector<int> vec(4);

	for (int i = 1; i <= 3; i++) {
		cin >> n;
		small[i] = n;
		big[i] = n;
	}

	for (int i = 2; i <= N; i++) {
		for (int j = 1; j <= 3; j++) {
			cin >> n;
			vec[j] = n;
		}
		smallest(vec);
		biggest(vec);
	}

	int big_num = 0, small_num = 987654321;
	for (int i = 1; i <= 3; i++) {
		if (big_num < big[i])
			big_num = big[i];
		if (small_num > small[i])
			small_num = small[i];
	}
	cout << big_num << " " << small_num << endl;

	system("pause");
	return 0;
}