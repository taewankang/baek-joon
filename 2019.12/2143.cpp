/*
값을 저장한 두 개의 배열에 더블 포인터를 이용해서 문제를 해결하려다가 답을 본 문제
코드 참고: https://jaimemin.tistory.com/1111
새로운 배열에 연속된 배열의 총합을 저장하고 이를 lower_bound, upper_bound를 이용해서 문제를 해결할 수 있다는 것을 생각하지 못했다.
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	long long T;
	int N, M, n, m;
	vector<int> vec1, vec2, sum1, sum2;
	cin >> T;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> n;
		vec1.push_back(n);
	}

	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> m;
		vec2.push_back(m);
	}

	for (int i = 0; i < N; i++) {
		int start = vec1[i];
		sum1.push_back(start);
		for (int j = i + 1; j < N; j++) {
			start += vec1[j];
			sum1.push_back(start);
		}
	}

	for (int i = 0; i < M; i++) {
		int start = vec2[i];
		sum2.push_back(start);
		for (int j = i + 1; j < M; j++) {
			start += vec2[j];
			sum2.push_back(start);
		}
	}

	sort(sum1.begin(), sum1.end());		//greater로 정렬하면 내림차순으로 정렬 됨
	sort(sum2.begin(), sum2.end());

	long long result = 0;
	for (int i = 0; i < sum1.size(); i++)
	{
		vector<int>::iterator low = lower_bound(sum2.begin(), sum2.end(), T - sum1[i]);
		vector<int>::iterator high = upper_bound(sum2.begin(), sum2.end(), T - sum1[i]);
		result += *high - *low;
	}
	cout << result << endl;
	system("pause");
	return 0;
}
