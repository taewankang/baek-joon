#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;
vector<vector<int>> vec(21);
bool check[21];
int N, n;
vector<int> total;

void find_diff(vector<int> v1, vector<int> v2) {
	int sum1 = 0, sum2 = 0;
	for (int i = 0; i < v1.size(); i++) {
		for (int j = 0; j < v1.size(); j++) {
			if (i == j)	continue;
			sum1 += vec[v1[i]][v1[j]];
			sum2 += vec[v2[i]][v2[j]];
		}
	}
	total.push_back(abs(sum1 - sum2));
}

void recur(int idx, int cnt) {
	if (cnt == N / 2) {
		vector<int> v1, v2;
		for (int i = 1; i <= N; i++) {
			if (check[i] == true)
				v1.push_back(i);
			else
				v2.push_back(i);
		}
		find_diff(v1, v2);
	}

	for (int i = idx; i <= N; i++) {
		if (check[i] == true)	continue;
		check[i] = true;
		recur(i, cnt + 1);
		check[i] = false;
	}
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		vec[i].push_back(0);
		for (int j = 1; j <= N; j++) {
			cin >> n;
			vec[i].push_back(n);
		}
	}

	recur(1, 0);

	sort(total.begin(), total.end());
	cout << total[0] << endl;

	system("pause");
	return 0;
}