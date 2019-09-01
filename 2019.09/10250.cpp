#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> vec(15);
int H, W, N;

int room_number() {
	int floor = N % H;
	int ho = N / H + 1;
	if (floor == 0) {
		floor = H;
		ho--;
	}
	floor *= 100;
	return floor + ho;
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> H >> W >> N;
		cout << room_number() << endl;
	}
	system("pause");
	return 0;
}