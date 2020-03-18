/*
	C보다 큰 수 중에서도 최소 비용이 나올 수도 있기 때문에 C + maximum의 범위까지 확인해준다.
*/
#include<iostream>
#include<vector>
using namespace std;
int C, N;
int arr[21][2];
vector<int> map(1101, 0);
int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> C >> N;
	int cost, person, maximum = 0;
	for (int i = 0; i < N; i++) {
		cin >> cost >> person;
		arr[i][0] = cost;
		arr[i][1] = person;
		maximum < person ? maximum = person : NULL;		//사람 수를 입력받았을 때 가장 큰 수를 maximum변수에 저장한다.
	}

	for (int i = 1; i <= C + maximum; i++) {		//최대로 확인해야 하는 범위가 C가 아닌 C + maximum까지이다.
		int minimum = 123456789;
		for (int j = 0; j < N; j++) {
			if (i - arr[j][1] < 0) {
				if ((minimum > arr[j][0])) minimum = arr[j][0];
				continue;
			}
			if (map[i - arr[j][1]] + arr[j][0] < minimum) 
				minimum = map[i - arr[j][1]] + arr[j][0];
		}
		if (minimum != 123456789) map[i] = minimum;
	}

	int result = 123456789;
	for (int i = C; i <= C + maximum; i++)			//C보다 큰 수 중에도 최소 비용이 나올 수 있다.
		result > map[i] ? result = map[i] : NULL;
	cout << result << endl;
	system("pause");
	return 0;
}
