#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
int sequence(int A, int P) {	//다음 수열 구하기
	int result = 0;
	vector<int> vec;
	while (A >= 1) {
		vec.push_back(A % 10);
		A /= 10;
	}
	for (int i = 0; i < vec.size(); i++)
		result += pow(vec[i], P);
	return result;
}

int main(void) {
	int A, P;
	cin >> A >> P;
	int i = 0;
	bool finish = false;
	vector<int> vec;
	vec.push_back(A);
	while (1) {
		int n = sequence(vec[vec.size() - 1], P);
		for (i = 0; i < vec.size(); i++) {
			if (vec[i] == n){	//반복되기 시작한다면
				finish = true;
				break;
			}
		}
		if (finish == true)
			break;
		else {
			vec.push_back(n);
		}
	}
	cout << i << endl;
	system("pause");
	return 0;
}
