#include<iostream>
#include<math.h>
using namespace std;
int main(void) {
	int T;
	long long start, end;
	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> start >> end;
		long long first = 0, second = 0;
		if (start > 0)
			first = ((start - 1) * start) / 2;
		else {
			first = (abs(start)*(abs(start)+1)) / 2;
		}
		if (end > 0)
			second = ((end)*(end + 1)) / 2;
		else
			second = ((abs(end))*(abs(end) - 1)) / 2;
		cout << "Scenario #" << i + 1 << ":\n";
		cout << second - first << "\n";
		cout << "\n";
	}
	system("pause");
	return 0;
}