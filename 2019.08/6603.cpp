#include<iostream>
#include<vector>
using namespace std;
vector<int> vec;
vector<int> result_vec(13);
int N, n;
void dfs(int start, int depth) {
	if (depth == 6) {
		for (int i = 0; i < 6; i++)
			cout << result_vec[i] << " ";
		cout << endl;
	}
	for (int i = start; i < N; i++) {
		result_vec[depth] = vec[i];
		dfs(i + 1, depth + 1);
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	while (1) {
		cin >> N;
		if (N == 0)
			break;
		vec.clear();
		for (int i = 0; i < N; i++) {
			cin >> n;
			vec.push_back(n);
		}
		dfs(0, 0);
		cout << endl;
	}
	system("pause");
	return 0;
}

