
#include <iostream>
#include<algorithm>
#include<string>
#include<string.h>
using namespace std;
int arr[1001][1001] = { 0, };
int main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	string s1, s2;
	cin >> s1 >> s2;
	for (int i = 0; i < s1.length(); i++) {
		for (int j = 0; j < s2.length(); j++) {
			if (s1[i] == s2[j])
				arr[i + 1][j + 1] = arr[i][j] + 1;
			else
				arr[i + 1][j + 1] = max(arr[i][j + 1], arr[i + 1][j]);
		}
	}
	cout << arr[s1.length()][s2.length()] << endl;
	system("pause");
	return 0;
}
