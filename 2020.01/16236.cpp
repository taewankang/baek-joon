#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int N;
vector<vector<int>> vec(21);
class Baby {
public:
	int y, x;
};

Baby baby;
int arr_x[4] = { 1, -1, 0, 0 };
int arr_y[4] = { 0, 0, 1, -1 };
int eating = 0, baby_size = 2;

bool compare(pair<int, int> a, pair<int, int> b) {
	if (a.first < b.first)
		return true;
	else if (a.first == b.first) {
		if (a.second < b.second) return true;
		return false;
	}
	return false;
}


void move_baby_shark(vector<pair<int, int>> food_list) {
	sort(food_list.begin(), food_list.end(), compare);
	baby.y = food_list[0].first;
	baby.x = food_list[0].second;
	vec[baby.y][baby.x] = 0;
}

bool find_food() {
	queue<pair<pair<int, int>, int>> q;		//y, x, distance
	bool check[21][21] = { false, };
	check[baby.y][baby.x] = true;
	vector<pair<int, int>> food_list;
	q.push({ {baby.y, baby.x}, 0 });
	int current_dist = -2;

	while (!q.empty()) {
		int y = q.front().first.first;
		int x = q.front().first.second;
		int dist = q.front().second;
		q.pop();
		if (current_dist + 1 == dist) {
			eating += current_dist + 1;
			move_baby_shark(food_list);
			return true;
		}

		for (int i = 0; i < 4; i++) {
			int next_y = y + arr_y[i];
			int next_x = x + arr_x[i];
			if (next_y > 0 && next_y <= N && next_x > 0 && next_x <= N && check[next_y][next_x] == false && vec[next_y][next_x] <= baby_size) {
				q.push({ {next_y, next_x}, dist + 1 });
				check[next_y][next_x] = true;
				if (vec[next_y][next_x] != 0 && vec[next_y][next_x] < baby_size) {
					current_dist = dist;
					food_list.push_back({ next_y, next_x });
				}
			}
		}
	}
	return false;
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> N;
	int n;
	for (int i = 1; i <= N; i++) {
		vec[i].push_back(0);
		for (int j = 1; j <= N; j++) {
			cin >> n;
			if (n == 9) {
				baby = { i, j };
				vec[i].push_back(0);
			}
			else
				vec[i].push_back(n);
		}
	}

	int idx = 0;
	while (1) {
		if (!find_food())
			break;
		idx++;
		if (idx == baby_size) {
			idx = 0;
			baby_size++;
		}
	}
	cout << eating << endl;
	system("pause");
	return 0;
}