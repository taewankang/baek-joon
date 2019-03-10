#include<iostream>
using namespace std;
int main(void) {
	int arr[31][31] = { 0, };
	int R, C, W;
	int result = 0;
	cin >> R >> C >> W;
	int c = C;
	arr[0][0] = 1;
	for (int i = 1; i < R + W - 1; i++) {
		arr[i][0] = 1;
		for (int j = 1; j < i; j++) {
			arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
		}
		arr[i][i] = 1;
	}

	for (int i = R - 1; i < R + W - 1; i++) {
		c++;
		for (int j = C - 1; j < c - 1; j++) {
				result += arr[i][j];
		}
	}
	cout << result << endl;
	system("pause");
	return 0;
}