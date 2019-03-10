#include<iostream>
#include<vector>
using namespace std;
bool paper[100][100];
void black(int x, int y) {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			paper[i + x][j + y] = 1;
		}
	}
}
int main(void) {
	int N, x, y;
	cin >> N;
	int result = 0;
	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		black(x, y);
	}
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++)
			if (paper[i][j] == 1)
				result++;
	}
	cout << result << "\n";
	system("pause");
	return 0;
}