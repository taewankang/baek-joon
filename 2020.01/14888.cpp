#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> number, opNum;
vector<char> op;
int minimum = 1000000000;
int maximum = -1000000000;

void calculate() {
	int result = number[0];
	for (int i = 1; i < number.size(); i++) {
		if (op[opNum[i - 1]] == '+') {
			result += number[i];
		}
		else if (op[opNum[i - 1]] == '-') {
			result -= number[i];
		}
		else if (op[opNum[i - 1]] == '*') {
			result *= number[i];
		}
		else if (op[opNum[i - 1]] == '/') {
			if (result < 0) {
				result *= -1;
				result /= number[i];
				result *= -1;
			}
			else
				result /= number[i];
		}
	}
	maximum < result ? maximum = result : NULL;
	minimum > result ? minimum = result : NULL;
}

void permu() {
	int k = 0;
	do {
		calculate();
	} while (next_permutation(opNum.begin(), opNum.end()));
	calculate();
}
int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int N, n, plus, minus, mul, divide;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> n;
		number.push_back(n);
	}
	cin >> plus >> minus >> mul >> divide;
	for (int i = 0; i < plus; i++) {
		op.push_back('+');
		opNum.push_back(opNum.size());
	}
	for (int i = 0; i < minus; i++) {
		op.push_back('-');
		opNum.push_back(opNum.size());
	}
	for (int i = 0; i < mul; i++) {
		op.push_back('*');
		opNum.push_back(opNum.size());
	}
	for (int i = 0; i < divide; i++) {
		op.push_back('/');
		opNum.push_back(opNum.size());
	}

	permu();
	cout << maximum << "\n" << minimum << "\n";
	system("pause");
	return 0;
}