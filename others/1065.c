1065
#include<iostream>
#include<string.h>
#include<string>
using namespace std;
class Han {
private:
	int num;
	int result = 0;
public:
	Han(int n) { num = n; }
	int get_result() { 
		if (num < 100)
			result = num;
		else 
			over_hundred();
		return result; 
	}
	int over_hundred() {
		result = 99;
		int hun, ten, one;	//���� �ڸ� ���� �ڸ� ���� �ڸ��� ��Ÿ���� ����
		int i = 110;		//110������ ��� ����� 99�� �����Ƿ�
		for (; i <= num; i++) {		
			hun = i / 100;
			ten = (i % 100) / 10;
			one = i % 10;
			if (ten * 2 == one + hun)	//���������� ����
				result++;
		}
		return result;
	}
};

int main(void) {
	int num;
	cin >> num;
	Han han(num);
	cout << han.get_result() << endl;
	system("pause");
	return 0;
}