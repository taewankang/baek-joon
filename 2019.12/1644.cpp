/*
	1. 소수만을 담은 배열인 vec을 만들기.
	2. 에라토스테네스의 체를 이용해서 vec에 소수만 저장하도록 구현
	3. vec의 연속된 소수의 총합을 저장할 vec2라는 배열을 생성.
	4. 만약 sum의 값이 N보다 크다면 저장할 필요가 없고 작거나 같다면 vec2에 push_back
	5. vec2를 돌면서 N과 같은 값이면 result개수를 1증가시킴
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