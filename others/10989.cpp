#include<iostream>
#include<vector>
#include<cstdio>
#include<stdio.h>
using namespace std;
int main(void) {
	int N, n;
	cin >> N;
	int i = 0, j = 0;
	int vec[10001] = { 0, };
	for (i = 0; i < N; i++) {		//10000개의 배열을 만들고 해당 수를 입력받을 때마다 
		scanf("%d", &n);			//배열을 1 증가시키고 나중에 배열에 저장되어 있는 수만큼 출력한다.
		vec[n]++;
	}

	for (i = 1; i <= 10000; i++) {
		for (j = 0; j < vec[i]; j++)
			printf("%d\n", i);
	}
	system("pause");
	return 0;
}