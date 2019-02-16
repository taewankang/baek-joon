#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
#include<string>
using namespace std;
bool check[26][26] = { 0, };
int N;
int result = 0;
vector<int> danji(650);
void dfs(int x, int y, vector<vector<int>> vec) {
	if (vec[y][x] == 1) {
		check[y][x] = true;
	}
	danji[result]++;

	for (int i = 0; i < 4; i++) {
		if (x > 0 && vec[y][x] == 1 && vec[y][x - 1] == 1 && check[y][x - 1] == false)
			dfs(x - 1, y, vec);
		else if (y > 0 && vec[y][x] == 1 && vec[y - 1][x] == 1 && check[y - 1][x] == false)
			dfs(x, y - 1, vec);
		else if (x < N - 1 && vec[y][x] == 1 && vec[y][x + 1] == 1 && check[y][x + 1] == false)
			dfs(x + 1, y, vec);
		else if (y < N - 1 && vec[y][x] == 1 && vec[y + 1][x] == 1 && check[y + 1][x] == false)
			dfs(x, y + 1, vec);
	}
}

int main(void) {
	string str;
	cin >> N;
	int n;
	vector<vector<int>> vec(N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++){
			scanf_s("%1d", &n);
			vec[i].push_back(n);
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (vec[i][j] == 1 && check[i][j]==false) {
				dfs(j, i, vec);
				result++;
			}
		}
	}
	sort(danji.begin(), danji.end());
	cout << result << endl;
	for (int i = 0; i < danji.size(); i++) {
		if (danji[i] == 0)
			continue;
		cout << danji[i] << "\n";
	}
	system("pause");
	return 0;
}