/*
4개의 배열에서 하나씩을 골랐을 때 합을 0을 만드는 문제였다.
배열 하나 크기가 4000이라 4중 for문을 돌리면 시간초과가 나기 때문에 불가능했다.
그래서 구글링을 해서 해결 방법을 알았다.
우선 배열을 두 개씩 잡고 더해서 최대 16,000,000개 크기의 배열을 만들어준 후 정렬을 시킨다.
그리고 더블 포인터를 이용해서 하나는 배열의 앞쪽부터 탐색하고 하나는 배열의 뒤쪽부터 탐색을 해 합이 0보다 크면 포인터를 하나 감소시키고 0보다 작으면 다른 포인터를 증가시키는 방법을 사용하였다.
그리고 합이 0일 때는 두 개의 포인터를 이동한 거리의 곱을 result에 더하는 방식으로 구현하였다.
코드 참조: https://yabmoons.tistory.com/290
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int N, n1, n2, n3, n4;
	long long result = 0;
	cin >> N;
	vector<int> v1(N), v2(N), v3(N), v4(N);
	for (int i = 0; i < N; i++) {
		cin >> n1 >> n2 >> n3 >> n4;
		v1[i] = n1;
		v2[i] = n2;
		v3[i] = n3;
		v4[i] = n4;
	}

	vector<int> result1, result2;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			result1.push_back(v1[i] + v2[j]);
			result2.push_back(v3[i] + v4[j]);
		}
	}
	sort(result1.begin(), result1.end());
	sort(result2.begin(), result2.end());
	int ptr1 = 0, ptr2 = result2.size() - 1;
	while (1) {
		if (ptr1 == result1.size() || ptr2 < 0)
			break;
		if (result1[ptr1] + result2[ptr2] > 0) {	//0보다 클 때
			ptr2--;
		}
		else if (result1[ptr1] + result2[ptr2] == 0) {
			int copy_ptr1 = ptr1;
			long long length1 = 0, length2 = 0;
			while (1) {
				if (ptr1 < result1.size() && result1[ptr1] + result2[ptr2] == 0) {
					ptr1++;
					length1++;
				}
				else
					break;
			}

			while (1) {
				if (ptr2 >= 0 && result1[copy_ptr1] + result2[ptr2] == 0) {
					length2++;
					ptr2--;
				}
				else
					break;
			}
			result += length1 * length2;
		}
		else if (result1[ptr1] + result2[ptr2] < 0) {
			ptr1++;
		}
	}
	cout << result << endl;
	system("pause");
	return 0;
}