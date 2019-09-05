#include<iostream>
#include<vector>
using namespace std;
bool bingo(vector<vector<int>>& vec) {
	int result = 0;
	bool bin = false;
	for (int i = 0; i < 5; i++) {
		if (vec[i][i] != -1) {
			break;
		}
		if (i == 4) 
			result++;
	}
	for (int i = 0; i < 5; i++) {
		if (vec[i][4 - i] != -1) {
			break;
		}
		if (i == 4)
			result++;
	}
	for (int i = 0; i < 5; i++) {
		if (vec[i][0] == -1 && vec[i][1] == -1 && vec[i][2] == -1 && vec[i][3] == -1 && vec[i][4] == -1) {
			result++;
		}
		if (result == 3)
			return true;
	}
	for (int i = 0; i < 5; i++) {
		if (vec[0][i] == -1 && vec[1][i] == -1 && vec[2][i] == -1 && vec[3][i] == -1 && vec[4][i] == -1)
			result++;
		if (result == 3)
			return true;
	}
	return false;
}

void find_num(vector<vector<int>> &vec, int target) {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (vec[i][j] == target) {
				vec[i][j] = -1;
				return;
			}
		}
	}
}

int main(void) {
	int n, counting = 0;
	vector<vector<int>> vec(5);
	vector<int> input;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> n;
			vec[i].push_back(n);
		}
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> n;
			input.push_back(n);
		}
	}
	for (int i = 0; i < 25; i++) {
		counting++;
		find_num(vec, input[i]);
		if (bingo(vec)) {
			cout << counting << "\n";
			system("pause");
			return 0;
		}
	}
	system("pause");
	return 0;
}