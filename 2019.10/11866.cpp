#include <iostream>
#include <list>
#include<vector>
using namespace std;
int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int N, K;
	cin >> N >> K;
	vector<int> vec;
	int pointer = 0, counting = N;
	list<int> li;
	for (int i = 1; i <= N; i++)
		li.push_back(i);
	list<int>::iterator iter = li.begin(), temp;
	while (1) {
		if (li.size() == 0)
			break;
		for (int i = 0; i < K - 1; i++) {
			iter++;
			if (iter == li.end())
				iter = li.begin();
		}
		vec.push_back(*iter);
		temp = iter;
		if (++temp == li.end()) {
			temp = li.begin();
		}
		li.remove(*iter);
		iter = temp;
	}
	cout << "<";
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i];
		if (i != vec.size() - 1)
			cout << ", ";
	}
	cout << ">" << endl;

	system("pause");
	return 0;
}
