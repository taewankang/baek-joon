/*
	1. �Ҽ����� ���� �迭�� vec�� �����.
	2. �����佺�׳׽��� ü�� �̿��ؼ� vec�� �Ҽ��� �����ϵ��� ����
	3. vec�� ���ӵ� �Ҽ��� ������ ������ vec2��� �迭�� ����.
	4. ���� sum�� ���� N���� ũ�ٸ� ������ �ʿ䰡 ���� �۰ų� ���ٸ� vec2�� push_back
	5. vec2�� ���鼭 N�� ���� ���̸� result������ 1������Ŵ
*/
#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

vector<int> prime(int N) {
	vector<int> vec(N + 1), vec2;
	for (int i = 2; i <= N; i++)
		vec[i] = i;
	for (int i = 2; i <= sqrt(N); i++) {
		if (vec[i] == 0)
			continue;
		for (int j = 2; i * j <= N; j++) {
			if (vec[i * j] != 0)
				vec[i * j] = 0;
		}
	}

	for (int i = 2; i < vec.size(); i++)
		if (vec[i] != 0)
			vec2.push_back(vec[i]);
	return vec2;
}


int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	vector<int> vec = prime(N);
	vector<int> vec2;
	for (int i = 0; i < vec.size(); i++) {
		int sum = vec[i];
		vec2.push_back(sum);
		for (int j = i + 1; j < vec.size(); j++) {
			sum += vec[j];
			if (sum > N)
				break;
			vec2.push_back(sum);
		}
	}
	int result = 0;
	for (int i = 0; i < vec2.size(); i++)
		if (vec2[i] == N)
			result++;
	cout << result << endl;
	system("pause");
	return 0;
}