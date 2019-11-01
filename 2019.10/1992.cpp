#include<iostream>
#include<vector>
#include<string>
#include<string.h>
using namespace std;
int N;
string result = "";
vector<vector<int>> vec(65);
int check(int y, int x, int size) {
	for (int i = y; i < y + size; i++) {
		for (int j = x; j < x + size; j++) {
			if (vec[y][x] != vec[i][j]) {
				return -1;
			}
		}
	}
	if (vec[y][x] == 1)
		return 1;
	else
		return 0;
}

void recursive(int y, int x, int size) {
	if (size == 0) {
		return;
	}
	int c = check(y, x, size);
	if (c == 0)
		result += '0';
	else if (c == 1)
		result += '1';
	else {
		result += '(';
		recursive(y, x, size / 2);
		recursive(y, x + size / 2, size / 2);
		recursive(y + size / 2, x, size / 2);
		recursive(y + size / 2, x + size / 2, size / 2);
		result += ')';
	}

}

int main(void) {
	int n;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		string str = "";
		cin >> str;
		vec[i].push_back(0);
		for (int j = 0; j < N; j++) {
			vec[i].push_back(str[j] - '0');
		}
	}
	recursive(1, 1, N);
	cout << result << endl;
	system("pause");
	return 0;
}