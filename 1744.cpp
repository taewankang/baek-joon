#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(void) {
	int N, n, sum = 0;
	cin >> N;
	vector<int> vec;
	vector<int> plus;
	vector<int> minus;
	bool min = false;
	for (int i = 0; i < N; i++) {
		cin >> n;
		vec.push_back(n);
	}
	sort(vec.begin(), vec.end());
	for (int i = 0; i < vec.size(); i++) {
		if (vec[i] >= 0) {
			plus.push_back(vec[i]);
		}
		else
			minus.push_back(vec[i]);
	}

	for (int i = plus.size() - 1; i >= 0; i -= 2) {
		if (i == 1) {
			if (plus[0] != 0) {
				if (plus[i] * plus[i - 1] > plus[i] + plus[i - 1])
					sum += plus[1] * plus[0];
				else
					sum += plus[1] + plus[0];
				break;
			}
			else {
				sum += plus[1];
				min = true;
				break;
			}
		}
		else if (i == 0) {
			if (plus[0] == 0) {
				min = true;
			}
			sum += plus[0];
			break;
		}
		if (plus[i] * plus[i - 1] > plus[i] + plus[i - 1])
			sum += plus[i] * plus[i - 1];
		else
			sum += plus[i] + plus[i - 1];
	}
	for (int i = 0; i < minus.size(); i+=2) {		//음수일 경우 만들기
		if (i == minus.size() - 2) {
			sum += minus[i] * minus[i + 1];
			break;
		}
		if (i == minus.size() - 1) {
			if (min == true)
				break;
			sum += minus[i];
			break;
		}
		sum += minus[i] * minus[i + 1];
	}
	cout << sum << endl;
	system("pause");
	return 0;
}