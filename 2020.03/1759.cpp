#include<iostream>
#include<vector>
#include<string>
#include<string.h>
#include<set>
#include<algorithm>
using namespace std;
vector<char> vec;
int L, C;
bool check[16] = { false, };
vector<string> result;
bool right_sentense(string str) {
	int ja = 0, mo = 0;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u')
			mo++;
		else
			ja++;
	}
	if (mo >= 1 && ja >= 2)
		return true;
	return false;
}

void permu(int idx, int cnt) {
	if (cnt == L) {
		string str = "";
		for (int i = 0; i < vec.size(); i++) {
			if (check[i] == true)
				str += vec[i];
		}
		if (right_sentense(str))
			result.push_back(str);
		return;
	}

	for (int i = idx; i < vec.size(); i++) {
		if (check[i] == true) continue;
		check[i] = true;
		permu(i, cnt + 1);
		check[i] = false;
	}
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	char c;
	cin >> L >> C;
	for (int i = 0; i < C; i++) {
		cin >> c;
		vec.push_back(c);
	}
	sort(vec.begin(), vec.end());
	permu(0, 0);
	for (int i = 0; i < result.size(); i++)
		cout << result[i] << "\n";
	system("pause");
	return 0;

}