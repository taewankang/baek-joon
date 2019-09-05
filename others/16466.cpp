#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;
int main(void) {
	int N;
	long long n;
	cin >> N;
	vector<long long> vec;
	vector<long long> ticket;
	bool finish = true;
	for (int i = 0; i < N; i++) {
		cin >> n;
		ticket.push_back(n);
	}

	sort(ticket.begin(), ticket.end());

	for (int i = 0; i <= ticket[ticket.size() - 1]; i++) {
		vec.push_back(i);
	}
	for (int i = 0; i < ticket.size(); i++) {
		vec[ticket[i]] = -1;
	}

	for (int i = 1; i < vec.size(); i++) {
		if (vec[i] != -1) {
			cout << vec[i] << "\n";
			finish = false;
			break;
		}
	}
	if (finish == true) {
		cout << ticket[ticket.size() - 1] + 1 << "\n";
	}
	system("pause");
	return 0;
}