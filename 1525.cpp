#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<map>
#include<string.h>
#include<string>
using namespace std;
vector<vector<int>> vec(4);
map<int, int> m;
const int RESULT = 123456789;
int x_arr[4] = { 1, 0, -1, 0 };
int y_arr[4] = { 0, 1, 0, -1 };
int bfs(int n) {
	queue<pair<int, int>> q;
	q.push({n, 0});
	int num = 0;
	while (!q.empty()) {
		int fr = q.front().first;
		int se = q.front().second;
		if (fr == RESULT)
			return se;
		q.pop();
		string str = to_string(fr);
		int location = str.find('9');
		int x = location / 3;
		int y = location % 3;
		for (int i = 0; i < 4; i++) {
			int nx = x + x_arr[i];
			int ny = y + y_arr[i];
			if (nx >= 0 && nx < 3 && ny >= 0 && ny < 3) {
				string next = str;
				swap(next[x * 3 + y], next[nx * 3 + ny]);
				int n = stoi(next);
				if (m.count(n) == 0){
					m[n] = m[fr] + 1;
					q.push({ n, se + 1 });
				}
			}
		}
	}
	return -1;
}

int main(void) {
	int n;
	int num = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> n;
			if (n == 0) 
				n = 9;
			num *= 10;
			num += n;
		}
	}
	m[num] = 0;
	cout << bfs(num) << "\n";
	system("pause");
	return 0;
}