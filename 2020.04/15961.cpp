#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N, d, k, c;
int maximum = 0, front_ptr, end_ptr = 0;
vector<pair<int, int>> vec(3003001);	//입력받은 값, 종류의 개수를 저장
int arr[3001] = { 0, };	//k개를 선택한 것 중에 중복이 있는지 확인하는 배열

void input() {
	int n;
	cin >> N >> d >> k >> c;
	for (int i = 0; i < N; i++) {
		cin >> vec[i].first;
		vec[i].second = 0;
	}
}

void add_data() {
	for (int i = N; i < N + k; i++) {
		vec[i].first = vec[i - N].first;
		vec[i].second = 0;
	}
}

void diff_smaller_k() {		//두 개의 포인터 차이가 k보다 작을 때(앞 포인터만 이동시킨다.)
	vec[0].second = 1;
	arr[vec[0].first] = 1;
	for (int i = 1; i < front_ptr; i++) {
		if (arr[vec[i].first] == 0)
			vec[i].second++;
		vec[i].second += vec[i - 1].second;
		arr[vec[i].first]++;
		if (maximum <= vec[i].second) {
			maximum = vec[i].second;
			arr[c] == 0 ? maximum++ : NULL;
		}
	}
}

void diff_is_k() {		//두 개의 포인터 차이가 k일 때(앞 포인터와 뒤 포인터를 둘 다 이동시킨다.)
	for (; front_ptr < N + k; front_ptr++, end_ptr++) {
		if (arr[vec[front_ptr].first] == 0)
			vec[front_ptr].second++;
		vec[front_ptr].second += vec[front_ptr - 1].second;
		arr[vec[front_ptr].first]++;

		if (maximum <= vec[front_ptr].second) {
			maximum = vec[front_ptr].second;
			arr[c] == 0 ? maximum++ : NULL;
		}
		--arr[vec[end_ptr].first] == 0 ? vec[front_ptr].second-- : NULL;
	}
}

void calculate() {
	diff_smaller_k();
	diff_is_k();
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	input();
	front_ptr = k - 1;	//투 포인터에서 앞을 가리키는 포인터
	add_data();	//배열이 원형을 만들 수 있도록 배열의 가장 뒤에 k만큼의 데이터를 더해준다.
	calculate();		//계산을 하는 함수
	cout << maximum << endl;
	return 0;
}