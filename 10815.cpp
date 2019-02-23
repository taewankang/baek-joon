#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>

using namespace std;
bool binary_search(vector<int>& vec, int search) {
	int start = 0; 
	int end = vec.size() - 1;
	int mid;
	while (1) {
		mid = (start + end) / 2;
		if (start > end)
			break;
		if (vec[mid] == search)
			return true;
		if (vec[mid] < search) {
			start = mid + 1;
		}
		else {
			end = mid -1;
		}
	}
	return false;
}

int main(void) {
	int N, M, m;
	scanf_s("%d", &N);
	vector<int> card(N);
	for (int i = 0; i < N; i++) {
		scanf_s("%d", &card[i]);	
	}
	scanf_s("%d", &M);
	vector<int> sang;
	for (int i = 0; i < M; i++) {
		scanf_s("%d", &m);
		sang.push_back(m);
	}

	sort(card.begin(), card.end());		//카드를 정렬한 후 binary search를 통해 해당 카드가 있는지 확인한다.
	for (int i = 0; i < sang.size(); i++) {
		if (binary_search(card, sang[i]))
			printf("1 ");
		else
			printf("0 ");
	}
	printf("\n");
	system("pause");
	return 0;
}
