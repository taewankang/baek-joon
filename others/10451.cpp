#include<iostream>
#include<vector>
using namespace std;
int result = 0;
int num_of_cycle = 0;
bool increase_cycle = false;

vector<pair<int, int>> recursive(vector<pair<int, int>>& vec, int i) {
	result = 0;
	if (vec[i].second == 0) {
		vec[i].second = 1;
		recursive(vec, vec[i].first);
		result++;
	}
	else if (vec[i].second == 1) {
			num_of_cycle++;
		return vec;
	}
	return vec;
}

int main(void) {
	int T;
	cin >> T;			//전체 테스트 케이스의 개수
	int t;
	for (int i = 0; i < T; i++) {
		num_of_cycle = 0;
		increase_cycle = false;
		vector<pair<int, int>> vec;
		int k = 0;					//pair의 second가 1인지 알려주는 변수
		int n;						//몇 개의 정수를 입력할 것인가
		int m = 1;
		vec.push_back(make_pair(0, 0));	//vec는 인덱스 1부터 시작
		cin >> t;
		for (int j = 0; j < t; j++) {
			cin >> n;
			vec.push_back(make_pair(n, 0));
		}
		while (k != t) {
			recursive(vec, m);
			k += result;
			m++;
			if (result == 0)
				num_of_cycle--;
		}
		cout << num_of_cycle << "\n";
	}
	system("pause");
	return 0;
}