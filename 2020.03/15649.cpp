#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N, M;
bool check[10] = { false, };
void recursive(int arr[], int depth) {
	if (depth == M + 1) {
		for (int i = 1; i <= M; i++)
			cout << arr[i] << " ";
		cout << "\n";
		return;
	}

	for (int i = 1; i <= N; i++) {
		if (check[i] == false) {
			arr[depth] = i;
			check[i] = true;
			recursive(arr, depth + 1);
			check[i] = false;
		}
	}
}

int main(void) {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> N >> M;
	int arr[9] = { 0, };

	for (int i = 1; i <= N; i++) {
		arr[1] = i;
		check[i] = true;
		recursive(arr, 2);
		check[i] = false;
	}

	system("pause");
	return 0;
}