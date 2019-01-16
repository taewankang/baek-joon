11726
#include<iostream>
#include<vector>
using namespace std;

int main(void) {
	int num = 0;
	cin >> num;
	vector<int> vec;
	if (num == 1)
		vec.push_back(1);
	else if (num == 2) {
		vec.push_back(1);
		vec.push_back(2);
	}
	else {
		vec.push_back(1);
		vec.push_back(2);
		for (int i = 2; i < num; i++)
			vec.push_back((vec[i - 1] + vec[i - 2])%10007);	//피보나치 수열
	}
	cout << vec[num-1] << endl;
	system("pause");
	return 0;
}
