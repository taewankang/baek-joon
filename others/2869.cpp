#include<iostream>
using namespace std;
int main(void) {
	long long A, B, V;
	cin >> A >> B >> V;
	long long day = 1;
	long long C = A - B;
	if (V <= A) {
		day = 1;
	}
	else {
		V -= A;
		day += V / C;
		if(V%C!=0)
			day += 1;
	}
	cout << day << endl;
	system("pause");
	return 0;
}