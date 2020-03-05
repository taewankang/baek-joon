/*
	백준 9095	1, 2, 3 더하기
	DP 를 이용해서 구현.
	N이 4일 때: (n이 1일 때의 경우의 수) + (n이 2일 때의 경우의 수) + (n이 3일 때의 경우의 수)
	N이 1일 때의 경우의 수 뒤에 3을 더하면 되고 n이 2일 때의 경우의 수 뒤에 2를 더하면 되고 n이 3일 때의 경우의 수 뒤에 1을 더하면 된다.
	이러한 방식으로 11까지 모든 수를 구한 다음 입력하는 조건에 맞춰 출력해주면 되는 문제.
*/
#include<iostream>
#include<vector>
using namespace std;
vector<int> vec(11, 0);
int recursive(int n) {
	int sum = 0;
	sum += vec[n - 1];
	sum += vec[n - 2];
	sum += vec[n - 3];
	return sum;
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int T, n;
	cin >> T;
	vec[1] = 1;
	vec[2] = 2;
	vec[3] = 4;
	for (int i = 4; i < 11; i++) {
		vec[i] = recursive(i);
	}

	for (int i = 0; i < T; i++) {
		cin >> n;
		cout << vec[n] << "\n";
	}
	system("pause");
	return 0;
}