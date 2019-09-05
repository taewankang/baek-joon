#include<iostream>
#include<math.h>
#include<vector>
using namespace std;

vector<int> so(int num) {
	vector<int> vec;
	int i = 2;
	while (1) {		//2부터 1씩 키워가며 나눠지는지 검사
		if (num <= 1)
			break;
		if (num % i == 0) {
			vec.push_back(i);
			num /= i;
			i = 2;
		}
		else
			i++;
	}
	return vec;
}

int main(void) {
	int N;
	cin >> N;
	vector<int> vec;
	vec=so(N);
	for (int i = 0; i < vec.size(); i++)
		cout << vec[i] << "\n";
	system("pause");
	return 0;
}