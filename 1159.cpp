#include<iostream>
#include<string.h>
#include<string>
#include<vector>
using namespace std;
int main(void) {
	int N;
	cin >> N;
	string str;
	int result = 0;
	int arr[27] = { 0, };
	for (int i = 0; i < N; i++) {
		cin >> str;
		arr[str[0] - 'a' + 1]++;	//arr[1]='a'
	}
	for (int i = 1; i <= 26; i++) {
		if (arr[i] >= 5) {
			printf("%c", 'a' + i - 1);
			result++;
		}
	}
	if (result == 0)
		printf("PREDAJA\n");
	else 
		printf("\n");
	system("pause");
	return 0;
}