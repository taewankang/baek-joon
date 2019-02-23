#include<iostream>
#include<math.h>
using namespace std;
int main(void) {
	int T = 0;
	cin >> T;
	int x1, y1, r1, x2, y2, r2;
	for (int i = 0; i < T; i++) {
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		if (x1 == x2 && y1 == y2 && r1 == r2) {
			cout << "-1\n";
			continue;
		}
		double distance = (double)sqrt(pow(abs(x1 - x2), 2) + pow(abs(y1 - y2), 2));
		cout << "distance: " << distance << endl;
		int radius_sum = r1 + r2;	//반지름의 합
		if (radius_sum < distance)
			cout << "0\n";
		else if (distance + r2 < r1)
			cout << "0\n";
		else if (distance + r1 < r2)
			cout << "0\n";
		else if (distance + r1 == r2)
			cout << "1\n";
		else if (distance + r2 == r1)
			cout << "1\n";
		else if (radius_sum == distance)
			cout << "1\n";
		else
			cout << "2\n";
	}
	system("pause");
	return 0;
}