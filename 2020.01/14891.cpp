#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> vec(5);

vector<int> input() {
	vector<int> v;
	char n;
	for (int i = 0; i < 8; i++) {
		cin >> n;
		v.push_back(n - '0');
	}
	return v;
}

void rotate_right(int idx) {
	vec[idx].push_back(vec[idx][0]);
	vec[idx].erase(vec[idx].begin());
}

void rotate_left(int idx) {
	vec[idx].insert(vec[idx].begin(), vec[idx][vec[idx].size() - 1]);
	vec[idx].pop_back();
}

void rotate(int cnt, int dir) {
	int start = cnt, end = cnt;
	bool bstart = false, bend = false;
	for (int i = cnt; i > 1; i--) {
		if (vec[i][6] == vec[i - 1][2]) {
			break;
		}
		else
			start--;
	}

	for (int i = cnt; i < 4; i++) {
		if (vec[i][2] == vec[i + 1][6]) {
			break;
		}
		else
			end++;
	}

	if (dir == 1) {
		rotate_left(cnt);
		for (int i = cnt - 1; i >= start; i--) {
			if (bstart == false) {
				rotate_right(i);
				bstart = true;
			}
			else if (bstart == true) {
				rotate_left(i);
				bstart = false;
			}
		}
		for (int i = cnt + 1; i <= end; i++) {
			if (bend == false) {
				rotate_right(i);
				bend = true;
			}
			else if (bend == true) {
				rotate_left(i);
				bend = false;
			}
		}
	}
	else {
		rotate_right(cnt);
		for (int i = cnt - 1; i >= start; i--) {
			if (bstart == false) {
				rotate_left(i);
				bstart = true;
			}
			else if (bstart == true) {
				rotate_right(i);
				bstart = false;
			}
		}
		for (int i = cnt + 1; i <= end; i++) {
			if (bend == false) {
				rotate_left(i);
				bend = true;
			}
			else  if (bend == true) {
				rotate_right(i);
				bend = false;
			}
		}
	}
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	vec[1] = input();
	vec[2] = input();
	vec[3] = input();
	vec[4] = input();


	int n, cnt, dir;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> cnt >> dir;
		rotate(cnt, dir);
	}

	int score = 0;
	if (vec[1][0] == 1)
		score += 1;
	if (vec[2][0] == 1)
		score += 2;
	if (vec[3][0] == 1)
		score += 4;
	if (vec[4][0] == 1)
		score += 8;
	cout << score << endl;

	system("pause");
	return 0;
}