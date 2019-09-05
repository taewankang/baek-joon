#include<iostream>
#include<string.h>
#include<string>
#include<math.h>
using namespace std;
int main(void) {
	string N;
	int B;
	long long result = 0;
	int num;
	cin >> N >> B;
	
	for (int i = 0; i < N.size(); i++) {
		if (N.at(i) >= 'A' && N.at(i) <= 'Z')
			num = N.at(i) - 55;
		else
			num = N.at(i) - 48;
		result += pow(B, N.size() - 1 - i)*num;
	}
	cout << result << endl;
	system("pause");
	return 0;
}