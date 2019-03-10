1929
#include<iostream>
#include<vector>
using namespace std;
int main(void) {
	vector<int> vec;	//에라토스테네스의 체를 이용
	int M, N;
	cin >> M >> N;
	for (int i = 0; i <= N; i++) {
		vec.push_back(i);
	}

	for (int i = 2; i * i <= N; i++) {
		for (int j = i * i; j <= N; j+=i) {
				vec[j] = -1;
		}
	}

	for (int i = 0; i < vec.size(); i++) {
		if (vec[i] >= M && vec[i] != -1 && vec[i] != 1)
			printf("%d\n", vec[i]);
	}
	system("pause");
	return 0;
}
