3486
#include<iostream> 
#include<math.h>
#include<string.h>
#include<string>
using namespace std;

int reverse_number(string num);

int main(void) {
	int num = 0;
	cin >> num;
	string str1, str2;
	int rev_str1, rev_str2, rev_sum=0;
	for (int i = 0; i < num; i++) {
		cin >> str1 >> str2;
		rev_str1=reverse_number(str1);	
		rev_str2 = reverse_number(str2);	
		rev_sum = rev_str1 + rev_str2;	
		rev_sum=reverse_number(to_string(rev_sum));	//뒤집은 숫자 둘을 더한 후 다시 뒤집어준다.
		cout << rev_sum << endl;
	}
	system("pause");
	return 0;
}

int reverse_number(string num) {		//숫자를 뒤집는 함수
	int str_to_int = stoi(num);
	int reverse = 0;
		for (int i = 0; i < num.length(); i++) {
			reverse += (str_to_int % 10) * pow(10, (num.length() - i - 1));
			str_to_int /= 10;
		}
	return reverse;
}