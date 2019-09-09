#include<iostream>
using namespace std;
int n;
double E, W, S, N;
double total = 0;
bool check[30][30] = { false, };
void backtracking(int depth) {
	/*
		백트래킹을 이용해서 방문하지 않은 곳을 찾아서 체크
	*/
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.precision(9);
	cout << fixed;
	cin >> n >> E >> W >> S >> N;
	E /= 100;	W /= 100;	S /= 100;	N /= 100;
	cout << E << " " << W << " " << N << " " << S << endl;
	backtracking();

	system("pause");
	return 0;
}