#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(void) {
	int N, num;
	cin >> N;
	vector<int> vec(1010);
	int big = 0;
	fill(vec.begin(), vec.end(), 0);
	int middle = 505;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> num;
			vec[middle - i + 2 * j] = max(vec[middle - i + 2 * j - 1], vec[middle - i + 2 * j + 1]) + num;			
		}
	}
	sort(vec.begin(), vec.end());
	cout << vec[vec.size() - 1] << "\n";



	system("pause");
	return 0;
}