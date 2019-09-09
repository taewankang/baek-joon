#include<iostream>
using namespace std;
int n;
double E, W, S, N;
double total = 0;
bool check[30][30] = { false, };
int x_arr[4] = { 1, -1, 0, 0 };
int y_arr[4] = { 0, 0, 1, -1 };
//이동 순서: E, W, S, N

double percentage(int i, double per) {
	switch (i) {
	case 0:
		per *= E;
		return per;
	case 1:
		per *= W;
		return per;
	case 2:
		per *= S;
		return per;
	case 3:
		per *= N;
		return per;
	}
}

void backtracking(int y, int x, int depth, double percen) {
	if (depth == n) {
		total += percen;
		return;
	}
	for (int i = 0; i < 4; i++) {
		int next_x = x + x_arr[i];
		int next_y = y + y_arr[i];
		if (next_x >= 15 - n && next_x <= 15 + n && next_y >= 15 - n && next_y <= 15 + n && check[next_y][next_x] == false) {
			check[next_y][next_x] = true;
			double copy_percen = percentage(i, percen);
			backtracking(next_y, next_x, depth + 1, copy_percen);
			check[next_y][next_x] = false;
		}
	}
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.precision(9);
	cout << fixed;
	cin >> n >> E >> W >> S >> N;
	E /= 100;	W /= 100;	S /= 100;	N /= 100;
	check[15][15] = true;
	backtracking(15, 15, 0, 1);
	cout << total << "\n";
	system("pause");
	return 0;
}