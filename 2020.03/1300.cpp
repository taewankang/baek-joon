/*
	시간복잡도: logN
	이 문제를 해결할 때 가장 중요한 것은 내가 넣은 input이 배열의 몇번째에 있는지 알아야 한다는 것
	find_order함수를 이용해서 이를 알아내고 이분탐색을 통해 원하는 수를 찾아준다.
*/

#include <iostream>
#include<algorithm>
using namespace std;
int N, K;

int find_order(int num) {
	int result = 0;
	for (int i = 1; i <= N; i++)
		result += min(N, num / i);
	return result;
}

int main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> N >> K;
	long long start = 1;
	long long end = K;
	int mid = 0, result;
	while (start <= end) {			//이분 탐색 기본 조건
		mid = (start + end) / 2;
		int calc_mid = find_order(mid);
		if (calc_mid >= K) {
			end = mid - 1;
			result = mid;
		}
		else {
			start = mid + 1;
		}
	}
	cout << result << endl;
	return 0;
}
