/*
4���� �迭���� �ϳ����� ����� �� ���� 0�� ����� ��������.
�迭 �ϳ� ũ�Ⱑ 4000�̶� 4�� for���� ������ �ð��ʰ��� ���� ������ �Ұ����ߴ�.
�׷��� ���۸��� �ؼ� �ذ� ����� �˾Ҵ�.
�켱 �迭�� �� ���� ��� ���ؼ� �ִ� 16,000,000�� ũ���� �迭�� ������� �� ������ ��Ų��.
�׸��� ���� �����͸� �̿��ؼ� �ϳ��� �迭�� ���ʺ��� Ž���ϰ� �ϳ��� �迭�� ���ʺ��� Ž���� �� ���� 0���� ũ�� �����͸� �ϳ� ���ҽ�Ű�� 0���� ������ �ٸ� �����͸� ������Ű�� ����� ����Ͽ���.
�׸��� ���� 0�� ���� �� ���� �����͸� �̵��� �Ÿ��� ���� result�� ���ϴ� ������� �����Ͽ���.
�ڵ� ����: https://yabmoons.tistory.com/290
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
		if (result1[ptr1] + result2[ptr2] > 0) {	//0���� Ŭ ��
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