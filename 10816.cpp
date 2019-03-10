#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int binary_search(vector<pair<int, int>> &vec, int search) {	//���� ī�带 ������ �ִ��� �Ǵ�
	int start = 0;
	int end = vec.size() - 1;	//�ߺ��� ������ �˱� ���� ����Լ��� �̿��ؼ� mid���� +1�� -1�� �ذ���
	while (1) {					//��� �ߺ��Ǿ������� Ȯ���ϴ� ����� �ִ�.
		if (start > end)
			break;
		int mid = (start + end) / 2;
		if (search > vec[mid].first) {
			start = mid + 1;
		}
		else if (search == vec[mid].first) {
			return vec[mid].second;
			//result=twosearch(left, mid-1, count, searchnum);	�� �̿��Ҽ��� �ִ�.
			//result++twosearch(mid+1, right, count, searchnum);
			//result+=1;
		}
		else
			end = mid - 1;
	}
	return -1;
}


int main(void) {
	int N, M, n, m;
	cin >> N;
	bool new_sang = false;
	vector<pair<int, int>> new_sang_vec;
	vector<pair<int, int>> sang;	//card�� ������ �� ����̰� ������ �ִ� ī�带 binary search�� �̿��ؼ�
	vector<pair<int, int>> card;	//���� ī�带 ������ �ִ��� �˻��Ѵ�.
	for (int i = 0; i < N; i++) {	
		cin >> n;
		sang.push_back({ n, 1 });
	}
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> m;
		card.push_back({ m, 1 });
	}
	sort(sang.begin(), sang.end());
	for (int i = 0; i < sang.size()-1; i++) {
		if (sang[i].first == sang[i + 1].first) {	//�ߺ��Ǵ� ī�带 ������ �ִٸ� ������ ������Ų��.
			sang[i + 1].second = sang[i].second;
			sang[i + 1].second++;
		}
		else if (sang[i].first != sang[i + 1].first) {
			new_sang_vec.push_back({ sang[i].first, sang[i].second });
		}		
	}
	new_sang_vec.push_back({ sang[sang.size() - 1].first, sang[sang.size() - 1].second });
	for (int i = 0; i < card.size(); i++) {
		if (binary_search(new_sang_vec, card[i].first) != -1)
			cout << binary_search(new_sang_vec, card[i].first) << " ";
		else
			cout << "0 ";
	}
	cout << endl;
	system("pause");
	return 0;
}