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
	for (i = 0; i < N; i++) {		//10000���� �迭�� ����� �ش� ���� �Է¹��� ������ 
		scanf("%d", &n);			//�迭�� 1 ������Ű�� ���߿� �迭�� ����Ǿ� �ִ� ����ŭ ����Ѵ�.
		vec[n]++;
	}

	for (i = 1; i <= 10000; i++) {
		for (j = 0; j < vec[i]; j++)
			printf("%d\n", i);
	}
	system("pause");
	return 0;
}