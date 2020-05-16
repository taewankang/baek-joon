#include<iostream>
#include<string>
#include<string.h>
#include<vector>
using namespace std;
string result = "";
vector<string> vec;
string push_vector(string temp) {		// 들어오는 temp의 자리수를 4자리로 만들어준다.
	string str = "";
	for (int i = 0; i < 4 - temp.length(); i++)
		str += "0";
	str += temp;
	return str;
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	string input = "", temp = "", copy_input = "";
	int col = 0, cnt_col = 0;
	cin >> input;
	for (int i = 0; i < input.length(); i++)
		if (input[i] == ':')
			col++;

	for (int i = 0; i < input.length() - 1; i++) {
		if (input[i] == ':') cnt_col++;
		copy_input += input[i];
		if (input[i] == ':' && input[i + 1] == ':') {
			for (int j = 0; j < 7 - col; j++)
				copy_input += ':';
		}
	}
	if (!(input[input.length() - 1] == ':' && cnt_col == 7))
		copy_input += input[input.length() - 1];

	input = copy_input;

	for (int i = 0; i < input.length(); i++) {
		if (input[i] == ':') {
			vec.push_back(push_vector(temp));
			temp = "";
		}
		else
			temp += input[i];
	}

	vec.push_back(push_vector(temp));
	for (int i = 0; i < vec.size(); i++) {
		result += vec[i];
		if (i != vec.size() - 1)
			result += ':';
	}
	cout << result << endl;

	return 0;
}
