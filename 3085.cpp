#include<iostream>
#include<vector>
#include<string>
#include<string.h>
using namespace std;
int x[4] = { 1, -1, 0, 0 }, y[4] = {0, 0, 1, -1};
int maximum = 1, N;
vector<vector<char>> vec(51);
void check(int x, int y) {
	int result = 0;
	int start = 0;
	for (int i = 0; i < vec[x].size(); i++) {
		if (vec[y][start] == vec[y][i]) {
			result++;
		}
		else {
			start = i;
			if (result > maximum)	maximum = result;
			result = 1;
		}
	}
	if (result > maximum)	maximum = result;
	start = 0;
	result = 0;
	for (int i = 0; i < vec[y].size(); i++) {
		if (vec[start][x] == vec[i][x]) {
			result++;
		}
		else {
			start = i;
			if (result > maximum)	maximum = result;
			result = 1;
		}
	}
	if (result > maximum)	maximum = result;
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	cin >> N;
	string str;
	for (int i = 0; i < N; i++) {
		cin >> str;
		for (int j = 0; j < str.length(); j++) {
			vec[i].push_back(str[j]);
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < 4; k++) {
				int new_x = j + x[k];
				int new_y = i + y[k];
				if (new_x >= 0 && new_x < N && new_y >= 0 && new_y < N) {					
					swap(vec[i][j], vec[new_y][new_x]);
					check(j, i);
					swap(vec[i][j], vec[new_y][new_x]);
				}
			}
		}
	}
	cout << maximum << "\n";
	system("pause");
	return 0;
}
