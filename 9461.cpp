#include<iostream>
#include<vector>
using namespace std;
int main(void) {
	vector<long long> vec(101);
	vec[0]=0;
	vec[1]=1;	// 1
	vec[2]=1;	// 2
	vec[3]=1;	// 3
	vec[4]=2;	// 4
	vec[5]=2;	// 5
	for (int i = 6; i < 101; i++) {
		vec[i] = vec[i - 5] + vec[i - 1];
	}
	int T;
	int N;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N;
		cout << vec[N]<<"\n";
	}
	system("pause");
	return 0;
}