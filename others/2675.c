2675
#include<iostream>
#include<string>
#include<string.h>
using namespace std;

int main(void) {
	int T;		//테스트 캐이스의 개수
	int R;		//테스트 케이스의 반복 횟수
	int par;	//문자열의 몇 번째 글자인지 나타내는 문자
	string S;	
	cin >> T;
	
	for (int i = 0; i < T; i++) {
		cin >> R;
		cin >> S;	
		par = 0;
		for (int j = 0; j < S.length(); j++) {	//입력받은 개수만큼 문자를 출력
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