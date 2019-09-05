#include<iostream>
#include<vector>
using namespace std;
int main(void) {
	int N, M, counting=0;
	while (~scanf_s("%d %d", &N, &M)) {
		counting = 0;
		for (int i = N; i <= M; i++) {
			bool room = true;
			vector<int> vec(10, 0);
			int n = i;
			while (n >= 1) {
				if(vec[n%10] == 0)
					vec[n % 10]++;
				else {
					room = false;
					break;
				}
				n /= 10;
			}
			if(room == true)
				counting++;
		}
		cout << counting << endl;
	}
	system("pause");
	return 0;
}