1158
#include<iostream>
#include<vector>
using namespace std;
int main(void) {
	vector<int> vec;
	vector<int> jose;
	int N, M;
	cin >> N >> M;
	int count = 0;
	int i = 0;
	int j = 0;
	int comma = 0;	//','�� ���� ���� ����
	for (int i = 0; i < N; i++)	//1���� N���� vec�� ���� 
		vec.push_back(i + 1);
	
	while(count != N) {		//��� �� ���ŵ� ������
		j = 0;
		while (j != M) {	//M���� ����������
			if (i >= N)
				i %= N;
			if (vec[i] == -1) {		//���ŵ� �ڸ���� ���� �ڸ��� Ȯ���Ѵ�.
				i++;
			}
			else if (vec[i] != -1) {	//���ŵ��� ���� �ڸ���� ����� ���� ���� �ڸ��� Ȯ���Ѵ�.
				j++;
				i++;
			}
		}
		jose.push_back(vec[i-1]);
		vec[i - 1] = -1;			//�ڸ��� ���ֱ� ���� -1�� �������ش�.
		count++;
	}

	cout << "<";
	for (int i = 0; i < jose.size(); i++) {
		cout << jose[i];
		comma++;
		if (comma == N)
			break;
		cout << ", ";
	}
	cout << ">"<< endl;
	system("pause");
	return 0;
}