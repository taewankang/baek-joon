#include <iostream>
#include <vector>
#include<list>
#include<algorithm>
using namespace std;

int main(void) {
	int N, M, n, index = 1;
	cin >> N >> M;
	int result = 0;
	list<int> li;
	for (int i = 0; i < N; i++) {
		li.push_back(i + 1);
	}


	vector<int> vec;
	for (int i = 0; i < M; i++) {
		cin >> n;
		vec.push_back(n);
	}

	list<int>::iterator l_iter = li.begin();
	list<int>::iterator r_iter = li.begin();
	for (int i = 0; i < vec.size(); i++) {
		if (li.size() == 1)
			break;
		int left = 0, right = 0;
		while (1) {
			if (*l_iter == vec[i]) {
				break;
			}
			if (l_iter == li.begin()) {
				left++;
				l_iter = li.end();
				l_iter--;
				continue;
			}
			l_iter--;
			left++;
		}
		while (1) {
			if (r_iter == li.end()) {
				r_iter = li.begin();
				continue;
			}
			if (*r_iter == vec[i]) {
				if (++r_iter == li.end()) {
					r_iter = li.begin();
					break;
				}
				else {
					--r_iter;
					r_iter++;
					break;
				}
			}
			r_iter++;
			right++;
		}

		l_iter = r_iter;
		li.remove(vec[i]);
		result += min(left, right);
	}
	cout << result << endl;
	system("pause");
	return 0;
}