#include<iostream>
#include<vector>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int x1, y1, x2, y2, n;
	cin >> y1 >> x1;
	vector<vector<int>> vec1(101), vec2(101);
	for (int i = 1; i <= y1; i++) {
		vec1[i].push_back(0);
		for (int j = 1; j <= x1; j++) {
			cin >> n;
			vec1[i].push_back(n);
		}
	}

	cin >> y2 >> x2;
	for (int i = 1; i <= y2; i++) {
		vec2[i].push_back(0);
		for (int j = 1; j <= x2; j++) {
			cin >> n;
			vec2[i].push_back(n);
		}
	}

	vector<vector<int>> vec(y1 + 1);
	for (int i = 1; i <= y1; i++) {
		vec[i].push_back(0);
		for (int j = 1; j <= x2; j++) {
			int result = 0;
			for (int k = 1; k <= x1; k++)
				result += vec1[i][k] * vec2[k][j];
			vec[i].push_back(result);
		}
	}

	for (int i = 1; i <= y1; i++) {
		for (int j = 1; j <= x2; j++) {
			cout << vec[i][j] << " ";
		}
		cout << endl;
	}
	system("pause");
	return 0;
}