#include<iostream>
#include<vector>
using namespace std;
int main(void) {
	int N, ji, han;
	cin >> N >> ji >> han;
	int round = 1;
	vector<int> vec(N, 0);
	int count = 0, c;
	int counting = 0;
	for (int i = 1; i <= N; i++) {
		vec[i-1]=i;
	}
	while (1) {
		if (counting == vec.size())
			break;
		
		for (int i = 0; i < vec.size(); i++) {
			if (count == 0 && vec[i] != -1) {
				count=1;
				c = i;
			}
			else if (count == 1 && vec[i] != -1) {
				if ((vec[c] == ji && vec[i] == han) || (vec[c] == han && vec[i] == ji)) {
					cout << round << "\n";
					system("pause");
					return 0;
				}
				if (vec[i] == ji || vec[i] == han) {
					vec[c] = -1;
					counting++;
				}
				else if (vec[c] == ji || vec[c] == han) {
					vec[i] = -1;
					counting++;
				}
				else {
					vec[i] = -1;
					counting++;
				}
				count = 0;
			}
		}
		round++;
		count= 0;
	}
	system("pause");
	return 0;
}