#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N, n;
vector<int> num;
int c[4] = { 0 };
int maximum = -1234567890;
int minimum = 1234567890;
int cnt = 0;
void calculate(vector<int> vec) {
	cnt++;
	int sum = num[0];
	for (int i = 1; i < num.size(); i++) {
		switch (vec[i - 1]) {
		case 1:
			sum += num[i];
			break;
		case 2:
			sum -= num[i];
			break;
		case 3:
			sum *= num[i];
			break;
		case 4:
			if (sum < 0) {
				sum *= -1;
				sum /= num[i];
				sum *= -1;
			}
			else {
				sum /= num[i];
			}
			break;
		}
	}
	minimum > sum ? minimum = sum : NULL;
	maximum < sum ? maximum = sum : NULL;
}

void order(int a, int b, int c, int d) {
	vector<int> vec;
	for (int i = 0; i < a; i++)
		vec.push_back(1);
	for (int i = 0; i < b; i++)
		vec.push_back(2);
	for (int i = 0; i < c; i++)
		vec.push_back(3);
	for (int i = 0; i < d; i++)
		vec.push_back(4);
	do {
		calculate(vec);
	} while (next_permutation(vec.begin(), vec.end()));
}


int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> n;
		num.push_back(n);
	}

	for (int i = 0; i < 4; i++)
		cin >> c[i];

	for (int a = 0; a <= c[0]; a++) {
		for (int b = 0; b <= c[1]; b++) {
			for (int C = 0; C <= c[2]; C++) {
				for (int d = 0; d <= c[3]; d++) {
					if ((a + b + C + d) == N - 1) {
						order(a, b, C, d);
					}
				}
			}
		}
	}
	cout << maximum << "\n" << minimum << "\n";
	system("pause");
	return 0;

}