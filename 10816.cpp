#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int binary_search(vector<pair<int, int>> &vec, int search) {	//같은 카드를 가지고 있는지 판단
	int start = 0;
	int end = vec.size() - 1;	//중복된 개수를 알기 위해 재귀함수를 이용해서 mid에서 +1과 -1을 해가며
	while (1) {					//몇개가 중복되었는지를 확인하는 방법도 있다.
		if (start > end)
			break;
		int mid = (start + end) / 2;
		if (search > vec[mid].first) {
			start = mid + 1;
		}
		else if (search == vec[mid].first) {
			return vec[mid].second;
			//result=twosearch(left, mid-1, count, searchnum);	를 이용할수도 있다.
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
	vector<pair<int, int>> sang;	//card를 정렬한 후 상근이가 가지고 있는 카드를 binary search를 이용해서
	vector<pair<int, int>> card;	//같은 카드를 가지고 있는지 검사한다.
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
		if (sang[i].first == sang[i + 1].first) {	//중복되는 카드를 가지고 있다면 개수를 증가시킨다.
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