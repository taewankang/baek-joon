#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
#include<string>

using namespace std;
bool compare(string a, string b) {		//문제의 조건에 맞게 정렬 시키는 함수
	if (a.length() < b.length())
		return true;
	else if (a.length() == b.length()) {
		if (a < b)
			return true;
		else
			return false;
	}
	else
		return false;
}
int main(void) {
	vector<string> vec;
	vector<string>::iterator iter;
	string n;
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> n;
		vec.push_back(n);
	}

	sort(vec.begin(), vec.end(), compare);
	unique(vec.begin(), vec.end());		//중복된 것을 걸러준다.
	for (int i = vec.size(); i >= 0; i++)
		if (vec[i] == "")
			vec.pop_back();
	for (iter=vec.begin(); iter != end; iter++)
		cout << *iter << "\n";
	system("pause");
	return 0;
}