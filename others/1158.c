1158
#include<iostream>
#include<vector>
using namespace std;
int main(void) {
	vector<int> vec;
	vector<int> jose;
	int N, M;
	cin >> N >> M;
	int count = 0;
	int i = 0;
	int j = 0;
	int comma = 0;	//','를 쓰기 위한 변수
	for (int i = 0; i < N; i++)	//1부터 N까지 vec에 대입 
		vec.push_back(i + 1);
	
	while(count != N) {		//모두 다 제거될 때까지
		j = 0;
		while (j != M) {	//M명을 지날때까지
			if (i >= N)
				i %= N;
			if (vec[i] == -1) {		//제거된 자리라면 다음 자리를 확인한다.
				i++;
			}
			else if (vec[i] != -1) {	//제거되지 않은 자리라면 명수를 새고 다음 자리를 확인한다.
				j++;
				i++;
			}
		}
		jose.push_back(vec[i-1]);
		vec[i - 1] = -1;			//자리를 없애기 위해 -1을 대입해준다.
		count++;
	}

	cout << "<";
	for (int i = 0; i < jose.size(); i++) {
		cout << jose[i];
		comma++;
		if (comma == N)
			break;
		cout << ", ";
	}
	cout << ">"<< endl;
	system("pause");
	return 0;
}