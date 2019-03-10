#include<iostream>
#include<string.h>
#include<string>
#include<list>
using namespace std;
int main(void) {
	int T, n;
	char c;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> n;
		list<char> li;
		for (int j = 0; j < n; j++) {
			cin >> c;
			if (li.size() == 0)
				li.push_back(c);
			else {
				if (li.front() >= c)
					li.push_front(c);
				else
					li.push_back(c);
			}
		}
		for (list<char>::iterator ptr = li.begin(); ptr != li.end(); ptr++)
			cout << *ptr;
		cout << "\n";
	}
	system("pause");
	return 0;
}