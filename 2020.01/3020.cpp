/*
	1. ��, �Ʒ��� �ִ� ��ֹ����� ���̸� ������ �迭�� ����
	2. �� �迭�� �̿��ؼ� �ش� ���̿� ��� ��ֹ��� �ִ����� priority_queue�� ����
	3. �ּҰ��� top�� ���� ���� ������ ���ѷ����� ���������鼭 ���
*/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, H, n;
	cin >> N >> H;
	int cnt = 0, result = 0;
	vector<int> vec;
	vector<int> odd(H + 1), even(H + 1);
	for (int i = 1; i <= N; i++) {
		cin >> n;
		if (i % 2) 		//Ȧ��
			odd[n]++;
		else 				//¦��
			even[n]++;
	}

	for (int i = odd.size() - 1; i > 1; i--) {
		odd[i - 1] += odd[i];
	}

	for (int i = 2; i <= H; i++) {
		even[H + 1 - i] += even[H + 2 - i];
	}

	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 1; i <= H; i++)
		pq.push(odd[i] + even[H + 1 - i]);
	result = pq.top();
	while (1) {
		if (pq.top() != result)
			break;
		cnt++;
		pq.pop();
	}

	cout << result << " " << cnt << endl;
	system("pause");
	return 0;
}
