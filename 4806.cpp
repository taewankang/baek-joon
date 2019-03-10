#include<iostream>
#include<stdio.h>
using namespace std;
int main(void) {
	char c;
	int count = 0;
	while (~scanf("%c", &c)) {
		if (c == '\n')
			count++;
	}
	cout << count << "\n";
	system("pause");
	return 0;
}