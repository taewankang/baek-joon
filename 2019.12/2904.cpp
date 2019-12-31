/*
2019.12.31
1. prime() �Լ��� �̿��ؼ� �Ҽ��θ� �̷���� �迭�� �����ߴ�.
2. ���� �Է� ������ devide�Լ��� �̿��ؼ� ���μ������� ����� �������ش�.
3. ���� ū ������ pow(�ش� �Ҽ��� ���� ���� / N)�� ���ϸ鼭 ���ߴ�.
4. �ּ� �� ������ ������ ������� �ش� �Ҽ��� ���� ��� - �Ҽ��� ���� Ƚ����ŭ�� ���ϸ鼭 ���ߴ�.
*/

#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
vector<int> prime_vec;
vector<int> prime() {
	vector<int> vec(1000001), vec2;
	for (int i = 2; i <= 1000000; i++)
		vec[i] = i;
	for (int i = 2; i <= sqrt(1000000); i++) {
		if (vec[i] == 0)
			continue;
		for (int j = 2; i * j <= 1000000; j++)
			if (vec[i * j] != 0)
				vec[i * j] = 0;
	}

	for (int i = 2; i <= 1000000; i++)
		if (vec[i] != 0)
			vec2.push_back(vec[i]);
	return vec2;
}

vector<int> devide(int N) {
	vector<int> vec(prime_vec.size());
	while (N != 1) {
		for (int i = 0; i < prime_vec.size(); i++) {
			if (N % prime_vec[i] == 0) {
				vec[i]++;
				N /= prime_vec[i];
				break;
			}
		}
	}
	return vec;
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int N, n;
	long long aver = 1;
	int counting = 0;
	cin >> N;
	vector<int> vec;
	vector<vector<int>> all_vec(N);
	prime_vec = prime();

	for (int i = 0; i < N; i++) {
		cin >> n;
		all_vec[i] = devide(n);
	}

	for (int i = 0; i < prime_vec.size(); i++) {
		int sum = 0;
		for (int j = 0; j < N; j++) {
			sum += all_vec[j][i];
		}
		if (sum / N != 0) {
			int aver2 = sum / N;
			aver *= pow(prime_vec[i], aver2);
			for (int j = 0; j < N; j++) {
				if (all_vec[j][i] < aver2)
					counting += aver2 - all_vec[j][i];
			}
		}
	}

	cout << aver << " " << counting << endl;
	system("pause");
	return 0;
}