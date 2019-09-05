#include<iostream>
#include<vector>
#include<string>
#include<string.h>
using namespace std;
bool palidrome(int num) {		//�Ӹ������ �����ϴ°�
	string intstring = to_string(num);
	int j = 0;
	bool pal = true;
	for (int i = 0; i < intstring.length() / 2; i++) {
		j = intstring.length() - i - 1;
		if (intstring[i] != intstring[j]) {
			pal = false;
			break;
		}
	}
	return pal;
}

bool prime_number(int num) {		//�Ҽ��ΰ�
	bool prime = true;
	for (int i = 2; i * i <= num; i++) {
		if (num %i == 0) {
			prime = false;
			break;
		}			
	}
	return prime;
}

int main(void) {
	int N;
	cin >> N;
	int num = N;
	while (1) {
		if (num == 1) {
			cout << "2\n";
			break;
		}
		if (palidrome(num) && prime_number(num)) {
			cout << num << "\n";
			break;
		}
		else
			num++;
	}
	system("pause");
	return 0;
}