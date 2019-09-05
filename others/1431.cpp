#include<iostream>
#include<string.h>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
bool compare(string a, string b) {
	int a_sum = 0, b_sum = 0;
	if (a.length() < b.length())		//A와 B의 길이 비교
		return true;
	else if (a.length() == b.length()) {
		for (int i = 0; i < a.length(); i++) {		//A의 자리수의 합 구하기
			if (a[i] >= 48 && a[i] <= 57)
				a_sum += a[i]-48;
		}
		for (int i = 0; i < b.length(); i++) {		//B의 자리수의 합 구하기
			if (b[i] >= 48 && b[i] <= 57)
				b_sum += b[i]-48;
		}
		if (a_sum < b_sum)
			return true;
		else if (a_sum == b_sum) {				
			int i, j;
			for (i = 0; i < a.length(); i++) {		//문자가 오는 인덱스 구하기
				if (a[i] >= 65)
					break;
			}
			for (j = 0; j < b.length(); j++)
				if (b[j] >= 65)
					break;
			if (i > j)
				return true;
			else if (i == j) {
				if (a < b)
					return true;
				else
					return false;
			}
			else
				return false;
		}
		else
			return false;
	}
	else
		return false;
}


int main(void) {
	string s;
	vector<string> vec;
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> s;
		vec.push_back(s);
	}
	sort(vec.begin(), vec.end(), compare);
	for (int i = 0; i < vec.size(); i++)
		cout << vec[i] << "\n";
	system("pause");
	return 0;
}