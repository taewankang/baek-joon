#include<iostream>
#include<vector>
using namespace std;
vector<int> insu(int insu) {	//
	vector<int> vec;
	int i = 2;
	while (1) {
		if (insu <= 1)
			break;
		if (insu % i == 0) {
			vec.push_back(i);
			insu /= i;
			i = 2;
		}
		else
			i++;
	}
	return vec;
}

int main(void) {
	int A, B;
	cin >> A >> B;
	int min = 1, max = 1;
	vector<int> As;
	vector<int> Bs;
	As = insu(A);
	Bs = insu(B);
	for (int i = 0; i < As.size(); i++) {
		for (int j = 0; j < Bs.size(); j++) {
			if (As[i] >= Bs[j]) {
				if (As[i] == Bs[j]) {
					max *= As[i];	//최대공약수
					As[i] = -1;
					Bs[j] = -1;
					break;
				}
			}
			else
				break;
		}
	}
	min = max;
	for (int i = 0; i < As.size(); i++) {
		min *= As[i];		//최소공배수
	}
	for (int i = 0; i < Bs.size(); i++) {
		min *= Bs[i];
	}
	cout << max << "\n" << min << "\n";
	return 0;
}