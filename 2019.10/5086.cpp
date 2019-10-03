#include<iostream>
using namespace std;
int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int first = 1, second = 1;
	while (1) {
		cin >> first >> second;
		if (first == 0 && second == 0)
			break;
		if (first > second) {		//배수일 확률
			if (first % second == 0)
				cout << "multiple" << endl;
			else
				cout << "neither" << endl;
		}
		else {		//약수일 확률
			if (second % first == 0)
				cout << "factor" << endl;
			else
				cout << "neither" << endl;
		}
	}
	return 0;
}