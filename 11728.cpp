#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(void) {
	vector<int> A;
	vector<int> B;
	int N, M, n, m;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> n;
		A.push_back(n);
	}
	for (int i = 0; i < M; i++) {
		cin >> m;
		B.push_back(m);
	}

	for (int i = 0; i < B.size(); i++)	//A배열에 B를 더한다.
		A.push_back(B[i]);
	sort(A.begin(), A.end());
	for (int i = 0; i < A.size(); i++)
		cout << A[i] << " ";
	cout << "\n";

	system("pause");
	return 0;
}