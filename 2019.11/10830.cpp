#include<iostream>
#include<vector>
using namespace std;
int N, n;
vector<vector<long long>> result(6);
long long B;
vector<vector<long long>> multiply(vector<vector<long long>> vec1, vector<vector<long long>> vec2) {
	vector<vector<long long>> result(N + 1);
	for (int i = 1; i <= N; i++) {
		result[i].push_back(0);
		for (int j = 1; j <= N; j++) {
			long long res = 0;
			for (int k = 1; k <= N; k++)
				res += vec1[i][k] * vec2[k][j];
			result[i].push_back(res % 1000);
		}
	}
	return result;
}

void show(vector<vector<long long>> vec) {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << vec[i][j] << " ";
		}
		cout << endl;
	}
}

vector<vector<long long>> recursive(long long num, vector<vector<long long>> vec, int rest) {
	if (num == 1) {
		result = multiply(vec, vec);
		if (rest == 1)
			result = multiply(vec, result);
		return result;
	}
	if (rest == 1) {
		result = recursive(num / 2, vec, num % 2);
		if (num == B) {
			return result;
		}
		result = multiply(result, result);
		result = multiply(result, vec);
	}
	else {
		result = recursive(num / 2, vec, num % 2);
		if (num == B) {
			return result;
		}
		result = multiply(result, result);
	}
	return result;
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> N >> B;
	vector<vector<long long>> vec(N + 1);
	for (int i = 1; i <= N; i++) {
		vec[i].push_back(0);
		result[i].push_back(0);
		for (int j = 1; j <= N; j++) {
			cin >> n;
			vec[i].push_back(n);
			result[i].push_back(0);
		}
	}

	if (B == 1) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				cout << vec[i][j] % 1000 << " ";
			}
			cout << endl;
		}
	}
	else {
		result = recursive(B, vec, 0);
		show(result);
	}
	system("pause");
	return 0;
}
