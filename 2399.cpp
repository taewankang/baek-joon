#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;
int main(void) {
	int N;
	long long n;
	cin >> N;
	long long result = 0;
	vector<long long> vec;
	for (int i = 0; i < N; i++) {
		cin >> n;
		vec.push_back(n);
	}
	sort(vec.begin(), vec.end());
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			result += abs(vec[i] - vec[j]);		//정렬한 후 거리의 차이를 더한 후 출력
		}
	}
	cout << result << "\n";
	system("pause");
	return 0;
}
