#include<iostream>
#include<queue>
#include<vector>
#include<math.h>
using namespace std;
int N, M;
vector<pair<int, int>> house;
vector<pair<int, int>> chicken;
int chicken_cnt = 0;
int result = 987654321;
void find_distance(vector<int>& loc) {
	int distance = 0;
	for (int i = 0; i < house.size(); i++) {
		int dist = 987654321;
		for (int j = 0; j < loc.size(); j++) {
			dist = min(dist, abs(house[i].first - chicken[loc[j]].first) + abs(house[i].second - chicken[loc[j]].second));
		}
		distance += dist;
	}
	result > distance ? result = distance : NULL;
}


void start(int idx, vector<bool> real, int cnt) {
	if (cnt == chicken_cnt) {
		vector<int> loc;			//치킨이 있는 집을 정해주는 백터
		for (int i = 1; i < real.size(); i++) {
			if (real[i])
				loc.push_back(i);
		}
		find_distance(loc);
		return;
	}

	for (int i = idx; i <= chicken.size() - 1; i++) {
		if (real[i])	continue;
		real[i] = true;
		start(i, real, cnt + 1);
		real[i] = false;
	}
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> N >> M;
	int n;
	chicken.push_back({ 0, 0 });

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> n;
			if (n == 2) 
				chicken.push_back({ i, j });
			else if (n == 1) 
				house.push_back({ i, j });
		}
	}
	vector<bool> chick(chicken.size());

	for (int i = 1; i <= M; i++) {
		chicken_cnt = i;
		start(1, chick, 0);
	}
	cout << result << endl;
	system("pause");
	return 0;
}