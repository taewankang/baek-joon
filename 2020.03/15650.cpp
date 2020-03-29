#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;
int N, M;

void recursive(int depth, int num, vector<int> vec) {
	if (depth == M && vec.size() == M) {
		for (int i = 0; i < vec.size(); i++)
			cout << vec[i] << " ";
		cout << endl;
		return;
	}

	for (int i = num + 1; i <= N; i++) {
		vec.push_back(i);
		recursive(depth + 1, i, vec);
		vec.pop_back();
	}
}

int main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		vector<int> vec;
		vec.push_back(i);
		recursive(1, i, vec);
		vec.clear();
	}

	system("pause");
	return 0;
}
