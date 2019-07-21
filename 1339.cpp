#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;
double n, E, W, N, S;
double result = 0;
void dfs(vector<vector<bool>> vec, int x, int y, int counting, double res) {
	vec[y][x] = true;
	if (counting == n) {
		result += res;
		return;
	}
	if (x < 2 * n + 1 && vec[y][x + 1] == false)
		dfs(vec, x + 1, y, counting + 1, res * E);
	if (y < 2 * n + 1 && vec[y + 1][x] == false)
		dfs(vec, x, y + 1, counting + 1, res * S);
	if (x >= 0 && vec[y][x - 1] == false)
		dfs(vec, x - 1, y, counting + 1, res * W);
	if (y >= 0 && vec[y - 1][x] == false)
		dfs(vec, x, y - 1, counting + 1, res * N);
}

int main(void) {
	cin >> n >> E >> W >> N >> S;
	E /= 100;	W /= 100;	N /= 100;	S /= 100;
	vector<vector<bool>> vec(2 * n + 1);
	for (int i = 0; i < 2 * n + 1; i++) {
		for (int j = 0; j < 2 * n + 1; j++) {
			vec[i].push_back(false);
		}
	}

	dfs(vec, n, n, 0, 1);
	cout << fixed;
	cout << setprecision(10) << result << endl;
	system("pause");
	return 0;
}