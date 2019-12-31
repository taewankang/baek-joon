/*
2019.12.31
1. prime() 함수를 이용해서 소수로만 이루어진 배열을 생성했다.
2. 값을 입력 받으면 devide함수를 이용해서 소인수분해한 결과를 저장해준다.
3. 가장 큰 점수는 pow(해당 소수가 사용된 개수 / N)을 곱하면서 구했다.
4. 최소 몇 번만에 점수를 얻는지는 해당 소수가 사용된 평균 - 소수가 쓰인 횟수만큼을 더하면서 구했다.
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