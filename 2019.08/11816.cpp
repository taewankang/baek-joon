#include<iostream>
#include<string.h>
#include<string>
#include<algorithm>
#include<math.h>
using namespace std;
int oc_to_de(string str) {
	int result = 0;
	int j = 0;
	for (int i = str.length() - 1; i >= 1; i--) {
		result += (pow(8, j) * (str[i] - '0'));
		j++;
	}
	return result;
}

int hex_to_de(string str) {
	int result = 0;
	int j = 0;
	for (int i = str.length() - 1; i >= 2; i--) {
		if (str[i] >= '0' && str[i] <= '9')
			result += (pow(16, j) * (str[i] - '0'));
		else
			result += (pow(16, j) * (str[i] - 'a' + 10));
		j++;
	}
	return result;
}

int main(void) {
	string str;
	cin >> str;
	if (str[0] == '0' && str[1] == 'x') 
		cout << hex_to_de(str) << "\n";
	else if (str[0] == '0') 
		cout << oc_to_de(str) <<"\n";
	else
		cout << str << "\n";
	system("pause");
	return 0;
}
