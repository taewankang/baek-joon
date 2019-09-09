#include<iostream>
using namespace std;
int n;
double E, W, S, N;

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.precision(9);
	cout << fixed;
	cin >> n >> E >> W >> S >> N;
	E /= 100;	W /= 100;	S /= 100;	N /= 100;


	system("pause");
	return 0;
}