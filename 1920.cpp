#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
using namespace std;
bool binary_search(vector<int> &vec, int target) {
	int start = 0, end = vec.size() - 1;
	while (start <= end) {
		int mid = (start + end) / 2;
		if (target == vec[mid])
			return true;
		if (target >vec[mid]) {
			start = mid + 1;
		}
		else if (target < vec[mid])
			end = mid - 1;
	}
	return false;
}

int main(void) {
	int N, M, n;
	cin >> N;
	vector<int> A;
	vector<int> vec;
	for (int i = 0; i < N; i++) {
		scanf("%d", &n);
		A.push_back(n);
	}
	sort(A.begin(), A.end());		//정렬한 후 binary_search함수를 이용해서 존재하는지 확인
	cin >> M;
	for (int i = 0; i < M; i++) {
		scanf("%d", &n);
		if (binary_search(A, n))
			cout << "1\n";
		else
			cout << "0\n";
	}
	system("pause");
	return 0;
}
