#include<iostream>
using namespace std;
int main(void) {
	int N;
	cin >> N;
	int max = 0;
	int arr[10] = { 0, };
	if (N == 0)
		arr[0]++;
	while (N >= 1) {
		arr[N % 10]++;
		N /= 10;
	}
	int num;
	if ((arr[6] + arr[9]) % 2 == 0)
		num = (arr[6] + arr[9]) / 2;
	else
		num = (arr[6] + arr[9]) / 2 + 1;

	for (int i = 0; i < 10; i++) {
		if (arr[i] > max && (i != 6 && i != 9)) {
			max = arr[i];
		}
	}
	if (num > max)
		cout << num << endl;
	else
		cout << max << endl;

	system("pause");
	return 0;
}