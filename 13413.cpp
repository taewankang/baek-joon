#include<iostream>
#include<string.h>
#include<string>
#include<math.h>
using namespace std;
int main(void) {
	int T, n;
	cin >> T;
	string s1, s2;
	for (int t = 0; t < T; t++) {
		int s1_w = 0, s1_b = 0;
		cin >> n;
		cin >> s1 >> s2;
		for (int i = 0; i < s1.length(); i++) {
			if (s1[i] == 'W' && s2[i] == 'B')
				s1_w++;
			else if (s1[i] == 'B' && s2[i] == 'W')
				s1_b++;
		}
		int result = 0;
		if (s1_w > s1_b) {
			result += s1_w - s1_b;
			result += s1_b;
		}
		else {
			result += s1_b - s1_w;
			result += s1_w;
		}
		cout << result << "\n";
	}
	system("pause");
	return 0;
}