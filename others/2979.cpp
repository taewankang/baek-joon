#include<iostream>
#include<vector>
using namespace std;
int main(void) {
	int A, B, C, start, end, result = 0;
	cin >> A >> B >> C;
	vector<int> vec(101, 0);
	for (int i = 0; i < 3; i++) {
		cin >> start >> end;
		for (int j = start; j < end; j++) {
			vec[j]++;
		}
	}

	for (int i = 0; i < 101; i++) {
		if (vec[i] == 1)
			result += A;
		else if (vec[i] == 2)
			result += 2 * B;
		else if (vec[i] == 3)
			result += 3 * C;
	}
	cout << result << endl;
	system("pause");
	return 0;
}