/*
	���� 9095	1, 2, 3 ���ϱ�
	DP �� �̿��ؼ� ����.
	N�� 4�� ��: (n�� 1�� ���� ����� ��) + (n�� 2�� ���� ����� ��) + (n�� 3�� ���� ����� ��)
	N�� 1�� ���� ����� �� �ڿ� 3�� ���ϸ� �ǰ� n�� 2�� ���� ����� �� �ڿ� 2�� ���ϸ� �ǰ� n�� 3�� ���� ����� �� �ڿ� 1�� ���ϸ� �ȴ�.
	�̷��� ������� 11���� ��� ���� ���� ���� �Է��ϴ� ���ǿ� ���� ������ָ� �Ǵ� ����.
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