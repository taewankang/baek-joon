#include<iostream> 
#include<vector>
#include<algorithm>
using namespace std;
int main(void) {
	int N, B;
	vector<int> vec;
	cin >> N >> B;
	while (1) {
		if (N < 1)
			break;
		vec.push_back(N%B);
		N /= B;
	}
	reverse(vec.begin(), vec.end());
	for (int i = 0; i < vec.size(); i++) {
		char b='A';
		if (vec[i] > 9) {
			b += (int)(vec[i] - 10);
			cout << b;
		}
		else
			cout << vec[i];
	}
	cout << endl;
	system("pause");
	return 0;
}