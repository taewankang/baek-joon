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
		int hun, ten, one;	//백의 자리 십의 자리 일의 자리를 나타내는 변수
		int i = 110;		//110까지는 출력 결과가 99로 같으므로
		for (; i <= num; i++) {		
			hun = i / 100;
			ten = (i % 100) / 10;
			one = i % 10;
			if (ten * 2 == one + hun)	//등차수열의 조건
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