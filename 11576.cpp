#include<iostream>
#include<math.h>
#include<vector>
using namespace std;
int main(void) {
	vector<int> vec;
	int A, B, m;
	cin >> A >> B >> m;
	int n;
	int to_dec=0;
	for (int i = 0; i < m; i++) {
		cin >> n;
		to_dec += n * pow(A, m - i - 1);	//A진법을 10진수로 변환
	}
	while (1) {
		if (to_dec / B >= 1) {
			vec.push_back(to_dec % B);
			to_dec = to_dec / B;
		}
		else {
			vec.push_back(to_dec%B);
			break;			//B진법으로 변환
		}
	}
	for (int i = vec.size() -1; i >= 0; i--)
		cout << vec[i] << " ";
	cout << endl;

	system("pause");
	return 0;
}