#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
long long total = 0;
vector<int> vec;
int result = 0, maximum = 0;
void recursive(int num) {
	int tot = vec[num]*(vec.size() - num);
	if (maximum >= tot) {
		maximum -= tot;
		int val = vec[num];
		for (int i = num; i < vec.size(); i++) {
			vec[i] -= val;
		}
		result += val;
		recursive(num + 1);
	}
	else {
		result += maximum / (vec.size() - num);
		return;
	}
}

int main(void) {
	int N, n;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> n;
		vec.push_back(n);
		total += n;
	}

	cin >> maximum;
	sort(vec.begin(), vec.end());
	if (total <= maximum) {
		cout << vec[vec.size() - 1] << endl;
		system("pause");
		return 0;
	}

	recursive(0);
	cout << result << endl;
	system("pause");
	return 0;
}