#include<iostream>
using namespace std;
int n;
double E, W, S, N;
double total = 0;
bool check[30][30] = { false, };
void backtracking(int depth) {
	/*
		��Ʈ��ŷ�� �̿��ؼ� �湮���� ���� ���� ã�Ƽ� üũ
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