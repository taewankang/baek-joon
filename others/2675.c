2675
#include<iostream>
#include<string>
#include<string.h>
using namespace std;

int main(void) {
	int T;		//�׽�Ʈ ĳ�̽��� ����
	int R;		//�׽�Ʈ ���̽��� �ݺ� Ƚ��
	int par;	//���ڿ��� �� ��° �������� ��Ÿ���� ����
	string S;	
	cin >> T;
	
	for (int i = 0; i < T; i++) {
		cin >> R;
		cin >> S;	
		par = 0;
		for (int j = 0; j < S.length(); j++) {	//�Է¹��� ������ŭ ���ڸ� ���
			for (int k = 0; k < R; k++) {		
				cout << S.at(par);
			}
			par++;
		}
		cout << endl;
	}
	system("pause");
	return 0;
}