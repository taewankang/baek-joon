9012
#include<iostream>
#include<vector>
#include<string.h>
#include<string>
using namespace std;
int main(void) {
	int num;
	cin >> num;
	string str;
	int count = 0;
	for (int i = 0; i < num; i++) {
		cin >> str;
		count = 0;
		for (int j = 0; j < str.size(); j++) {
			if (str.at(j) == '(') {	//���� ��ȣ�� �Է����� ��� count���� ������Ų��.
				count++;
			}
			else if (str.at(j) == ')') {	//�ݴ� ��ȣ�� �Է����� ��� count���� ���ҽ�Ų��.
				count--;
			}
			if (count < 0)	���� ')'�� ���� �Է����� ��� count���� 0���� �۾����Ƿ� �̸� �����ϱ� ����
				break;
		}
		if (count == 0)	//��ȣ�� ���� ������ �ùٸ��� �ԷµǾ��� ��
			cout << "YES" << endl;
		else	//�ùٸ��� �Էµ��� �ʾ��� ��
			cout << "NO" << endl;
	}
	system("pause");
	return 0;
}