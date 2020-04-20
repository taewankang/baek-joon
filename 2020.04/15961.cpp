#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N, d, k, c;
int maximum = 0, front_ptr, end_ptr = 0;
vector<pair<int, int>> vec(3003001);	//�Է¹��� ��, ������ ������ ����
int arr[3001] = { 0, };	//k���� ������ �� �߿� �ߺ��� �ִ��� Ȯ���ϴ� �迭

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

void diff_smaller_k() {		//�� ���� ������ ���̰� k���� ���� ��(�� �����͸� �̵���Ų��.)
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

void diff_is_k() {		//�� ���� ������ ���̰� k�� ��(�� �����Ϳ� �� �����͸� �� �� �̵���Ų��.)
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
	front_ptr = k - 1;	//�� �����Ϳ��� ���� ����Ű�� ������
	add_data();	//�迭�� ������ ���� �� �ֵ��� �迭�� ���� �ڿ� k��ŭ�� �����͸� �����ش�.
	calculate();		//����� �ϴ� �Լ�
	cout << maximum << endl;
	return 0;
}