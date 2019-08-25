#include <iostream>
#include<algorithm>
using namespace std;
int main() {
	int T, A, B, C, day;
	cin >> T;
	int result = 0;
	for (int i = 0; i < T; i++) {
		result = 0;
		cin >> day;
		for (int j = 0; j < day; j++) {
			cin >> A >> B >> C;
			if (max(A, max(B, C)) > 0)
				result += max(A, max(B, C));
		}
		cout << result << endl;
	}
	
	system("pause");
	return 0;
}