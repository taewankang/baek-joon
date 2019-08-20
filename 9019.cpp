#include<iostream>
#include<vector>
#include<queue>
#include<string.h>
#include<string>
using namespace std;
bool check[10001];

int D_Func(int num) {
	num *= 2;
	if (num > 9999)
		return num % 10000;
	return num;
}
int S_Func(int num) {
	if (num < 1)
		return 9999;
	return (num - 1);
}
int L_Func(int num) {
	int fir = num / 1000;
	num %= 1000;
	num *= 10;
	num += fir;
	return num;
}
int R_Func(int num) {
	int la = num % 10;
	num /= 10;
	la *= 1000;
	num += la;
	return num;
}

string bfs(int A, int B) {
	queue<pair<int, string>> q;
	q.push({ A, "" });
	while (!q.empty()) {
		if (q.front().first == B)
			return q.front().second;
		int fr = q.front().first;
		string str = q.front().second;
		q.pop();
		int D = D_Func(fr);
		int S = S_Func(fr);
		int L = L_Func(fr);
		int R = R_Func(fr);
		if (check[D] == false) {
			q.push({ D, (str + "D") });
			check[D] = true;
		}
		if (check[S] == false) {
			q.push({ S, (str + "S") });
			check[S] = true;
		}
		if (check[L] == false) {
			q.push({ L, (str + "L") });
			check[L] = true;
		}
		if (check[R] == false) {
			q.push({ R, (str + "R") });
			check[R] = true;
		}
	}
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int T, t;
	cin >> T;
	for (int t = 0; t < T; t++) {
		int A, B;
		cin >> A >> B;
		for (int i = 0; i < 10001; i++)
			check[i] = false;
		vector<int> vec;
		cout <<bfs(A, B) << "\n";
	}
	system("pause");
	return 0;
}
