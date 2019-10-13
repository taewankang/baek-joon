#include <iostream>
#include <deque>
using namespace std;
int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int N;
	deque<int> deq;
	cin >> N;
	for (int i = N; i > 0; i--)
		deq.push_back(i);
	while (1) {
		if (deq.size() == 1)
			break;
		deq.pop_back();
		deq.push_front(deq.back());
		deq.pop_back();
	}
	cout << deq.back() << endl;
	system("pause");
	return 0;
}
