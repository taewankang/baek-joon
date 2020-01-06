/*
	1. 위, 아래에 있는 장애물들의 길이를 저장한 배열을 만듦
	2. 두 배열을 이용해서 해당 높이에 몇개의 장애물이 있는지를 priority_queue에 저장
	3. 최소값과 top의 값이 같지 않으면 무한루프를 빠져나오면서 출력
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
		if (i % 2) 		//홀수
			odd[n]++;
		else 				//짝수
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
