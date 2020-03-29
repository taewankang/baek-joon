/*
	�ð����⵵: logN
	�� ������ �ذ��� �� ���� �߿��� ���� ���� ���� input�� �迭�� ���°�� �ִ��� �˾ƾ� �Ѵٴ� ��
	find_order�Լ��� �̿��ؼ� �̸� �˾Ƴ��� �̺�Ž���� ���� ���ϴ� ���� ã���ش�.
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
	while (start <= end) {			//�̺� Ž�� �⺻ ����
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
