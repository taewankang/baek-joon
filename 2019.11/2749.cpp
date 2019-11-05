#include<iostream>
#include<vector>
using namespace std;
#define ll long long
#define endl "\n"
vector<vector<long long>> base(3), result(3);
long long N;

vector<vector<long long>> calculate(vector<vector<long long>> vec1, vector<vector<long long>> vec2) {
	vector<vector<long long>> temp(3);
	for (int i = 1; i < 3; i++) {
		temp[i].push_back(0);
		for (int j = 1; j < 3; j++) {
			long long res = 0;
			for (int k = 1; k < 3; k++) {
				res += vec1[i][k] * vec2[k][j];
			}
			temp[i].push_back(res % 1000000);
		}
	}
	return temp;
}

void make(long long num, int rest) {
	if (num == 1) {
		result = calculate(base, base);
		if (rest == 1)
			result = calculate(result, base);
		return;
	}
	if (rest == 1) {
		make(num / 2, num % 2);
		if (N - 1 == num)
			return;
		result = calculate(result, result);
		result = calculate(result, base);
	}
	else if (rest == 0) {
		make(num / 2, num % 2);
		if (N - 1 == num)
			return;
		result = calculate(result, result);
	}
}


int main(void) {
	cin >> N;
	if (N == 1) {
		cout << "1\n";
		return 0;
	}
	else if (N == 2) {
		cout << "1\n";
		return 0;
	}
	else {
		for (int i = 1; i < 3; i++) {
			base[i].push_back(0);
			result[i].push_back(0);
			for (int j = 1; j < 3; j++) {
				base[i].push_back(1);
				result[i].push_back(0);
			}
		}
		base[2][2] = 0;
		make(N - 1, 0);
	}
	cout << result[1][1] << endl;
	system("pause");
	return 0;
}