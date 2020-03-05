#include<iostream>
#include<vector>
using namespace std;
vector<int> vec;
bool check[50] = { 0, };
int N, n;

void permu(int idx, int cnt) {
	if (cnt == 6) {
		for (int i = 0; i < N; i++) {
			if (check[i] == true)
				cout << vec[i] << " ";
		}
		cout << "\n";
	}

	for (int i = idx; i < N; i++) {
		if (check[i] == true)	continue;
		check[i] = true;
		permu(i, cnt + 1);
		check[i] = false;
	}
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	while (1) {
		cin >> N;
		if (!N)
			break;
		vec.clear();
		for (int i = 0; i < 50; i++)
			check[i] = false;
		for (int i = 0; i < N; i++) {
			cin >> n;
			vec.push_back(n);
		}
		permu(0, 0);
		cout << "\n";
	}

	system("pause");
	return 0;

}