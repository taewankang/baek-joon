#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool binary_search(vector<int> &vec, int target) {
	int start = 0; int end = vec.size() - 1;
	while (start <= end) {
		int mid = (start + end) / 2;
		if (vec[mid] == target) {
			return true;
		}
		else if (vec[mid] < target)
			start = mid + 1;
		else if (vec[mid] > target)
			end = mid - 1;
	}
	return false;
}

int main(void) {
	int N, M, n;
	cin >> N >> M;
	vector<int> vec;
	int result = 0;
	for (int i = 0; i < N; i++) {
		scanf_s("%d", &n);
		vec.push_back(n);
	}
	sort(vec.begin(), vec.end());
	for (int i = 0; i < N; i++) {
		if (binary_search(vec, M - vec[i])) {	//두 값을 더해 M이 나와야 하므로 binary_search를 이용해서 
			result++;							//값을 찾을 때 M-vec[i]값이 있는지를 확인한다.
		}
	}
	cout << result / 2<<"\n";
	system("pause");
	return 0;
}
