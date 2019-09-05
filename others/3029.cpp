#include<iostream>
#include<string.h>
#include<string>
#include<vector>
using namespace std;
int main(void) {
	vector<int> vec1(3, 0);
	vector<int> vec2(3, 0);
	string t1, t2;
	int h, m, s;
	cin >> t1 >> t2;
	int j = 0;
	for (int i = 0; i < t1.length(); i++) {
		if (t1[i] - '0' >= 0 && t1[i] - '0' <= 9) {
			vec1[j] *= 10;
			vec1[j] += t1[i] - '0';
		}
		if (t1[i] == ':')
			j++;
	}
	j = 0;
	for (int i = 0; i < t2.length(); i++) {
		if (t2[i] - '0' >= 0 && t2[i] - '0' <= 9) {
			vec2[j] *= 10;
			vec2[j] += t2[i] - '0';
		}
		if (t2[i] == ':')
			j++;
	}
	if (vec2[2] >= vec1[2]) {
		s = vec2[2] - vec1[2];
	}
	else {
		if(vec2[1] > 0)
			vec2[1]--;
		else {
			if (vec2[0] > 0) {
				vec2[0]--;
				vec2[1] += 59;
			}
			else {
				vec2[0] += 23;
				vec2[1] += 59;
			}
		}
		vec2[2] += 60;
		s = vec2[2] - vec1[2];
	}
	if (vec2[1] >= vec1[1]) {
		m = vec2[1] - vec1[1];
	}
	else {
		if (vec2[0] > 0) {
			vec2[0]--;
			vec2[1] += 60;
		}
		else {
			vec2[0] += 23;
			vec2[1] += 60;
		}
		m = vec2[1] - vec1[1];
	}
	if (vec2[0] >= vec1[0]) {
		h = vec2[0] - vec1[0];
	}
	else {
		vec2[0] += 24;
		h = vec2[0] - vec1[0];
	}
	if (vec1[0] == vec2[0] && vec1[1] == vec2[1] && vec1[2] == vec2[2])
		h = 24;
	if (h >= 10) {
		cout << h << ":";
	}
	else {
		cout << "0" << h << ":";
	}
	if (m >= 10) {
		cout << m << ":";
	}
	else {
		cout << "0" << m << ":";
	}
	if (s >= 10) {
		cout << s << "\n";
	}
	else {
		cout << "0" << s << "\n";
	}
	system("pause");
	return 0;
}