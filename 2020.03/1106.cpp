/*
	C���� ū �� �߿����� �ּ� ����� ���� ���� �ֱ� ������ C + maximum�� �������� Ȯ�����ش�.
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
		maximum < person ? maximum = person : NULL;		//��� ���� �Է¹޾��� �� ���� ū ���� maximum������ �����Ѵ�.
	}

	for (int i = 1; i <= C + maximum; i++) {		//�ִ�� Ȯ���ؾ� �ϴ� ������ C�� �ƴ� C + maximum�����̴�.
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
	for (int i = C; i <= C + maximum; i++)			//C���� ū �� �߿��� �ּ� ����� ���� �� �ִ�.
		result > map[i] ? result = map[i] : NULL;
	cout << result << endl;
	system("pause");
	return 0;
}
