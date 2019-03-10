#include<iostream>
using namespace std;
int counting = 0;
int result = 2;
int recursive(int N, int start) {		
	if (counting == N) {
		return result;
	}
	else {
		result = result * 2 - 1;
		counting++;
		recursive(N, result);
	}
}

int main(void) {
	int N;
	cin >> N;
	int score = recursive(N, 2);
	cout << score * score << endl;

	system("pause");
	return 0;
}