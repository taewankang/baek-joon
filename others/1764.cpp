#include<iostream>
#include<string.h>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main(void) {
	string s1;
	string s2;
	int n1, n2;
	vector<string> vec;
	vector<string> result;
	int j = 0;
	cin >> n1 >> n2;
	for (int i = 0; i < n1; i++) {
		cin >> s1;
		vec.push_back(s1);
	}
	for (int i = 0; i < n2; i++) {
		cin >> s2;
		vec.push_back(s2);
	}
	sort(vec.begin(), vec.end());		//�� ���Ϳ� ��� �Է��ϰ� ������ �� �ߺ��� ���ڿ��� ����Ѵ�.
	for (int i = 0; i < vec.size() - 1; i++) {
		if (vec[i] == vec[i + 1]) {
			result.push_back(vec[i]);
			i++;
		}
	}
	cout << result.size() << "\n";
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << "\n";
	}
	system("pause");
	return 0;
}