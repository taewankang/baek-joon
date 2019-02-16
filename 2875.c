2875
#include<iostream>
using namespace std;
int main(void) {
	int N, M, K;	//N; 여자, M: 남자, K: 빼내야 하는 사람 수
	int N_rest = 0;
	int M_rest = 0;
	int team = 0;
	int rest = 0;
	cin >> N >> M >> K;
	if (M >= N/2) {		//남자의 수가 남을 경우
		rest = M - (N / 2);
		team = M - rest;
		if (K > rest) {
			while (1) {
				rest += 3;
				team -= 1;
				if (K <= rest)
					break;
			}
		}
	}
	else if (M * 2 < N) {	//여자의 수가 남을 경우
		rest = N - (M * 2);
		team = M;
		if (K > rest) {
			while (1) {
				rest += 3;
				team -= 1;
				if (K <= rest)
					break;
			}
		}
	}
	cout << team << endl;
	system("pause");
	return 0;
}
