#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int arr_x[4] = { 1, -1, 0, 0 };
int arr_y[4] = { 0, 0, 1, -1 };
int R, C, T;
int mec_x, mec_y;
vector<vector<int>> vec(51);
void expansion_dust() {
	int arr[51][51] = { 0, };
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if (vec[i][j] != 0 && vec[i][j] != -1) {
				int direction = 0;
				for (int k = 0; k < 4; k++) {
					int next_x = arr_x[k] + j;
					int next_y = arr_y[k] + i;
					if (next_x > 0 && next_x <= C && next_y > 0 && next_y <= R && vec[next_y][next_x] != -1) {
						arr[next_y][next_x] += (vec[i][j] / 5);
						direction++;
					}
				}
				vec[i][j] -= ((vec[i][j] / 5) * direction);
			}
		}
	}
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++)
			vec[i][j] += arr[i][j];
	}
}

void clean_dust() {
	int up = mec_y - 1;
	int down = mec_y;
	int temp1 = vec[up][2], temp2 = 0;
	queue<int> q_up, q_down;
	for (int i = 2; i < C ; i++) {
		q_up.push(vec[up][i]);
		q_down.push(vec[down][i]);
	}
	for (int i = up; i > 1; i--)	q_up.push(vec[i][C]);
	for (int i = down; i < R; i++)	q_down.push(vec[i][C]);
	for (int i = C; i > 1; i--) {
		q_up.push(vec[1][i]);
		q_down.push(vec[R][i]);
	}
	for (int i = 1; i < up; i++)	q_up.push(vec[i][1]);
	for (int i = R; i > down; i--)	q_down.push(vec[i][1]);

	vec[up][2] = 0;	vec[down][2] = 0;
	for (int i = 3; i < C; i++) {
		vec[up][i] = q_up.front();
		vec[down][i] = q_down.front();
		q_up.pop();
		q_down.pop();
	}
	for (int i = up; i > 1; i--) { vec[i][C] = q_up.front();	q_up.pop();}
	for (int i = down; i < R; i++) { vec[i][C] = q_down.front();	q_down.pop(); }
	for (int i = C; i > 1; i--) { 
		vec[1][i] = q_up.front(); q_up.pop(); 
		vec[R][i] = q_down.front(); q_down.pop();
	}
	for (int i = 1; i < up; i++) { vec[i][1] = q_up.front();	q_up.pop(); }
	for (int i = R; i > down; i--) { vec[i][1] = q_down.front();	q_down.pop();}
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n, result = 0;
	cin >> R >> C >> T;
	for (int i = 1; i <= R; i++) {
		vec[i].push_back(0);
		for (int j = 1; j <= C; j++) {
			cin >> n;
			vec[i].push_back(n);
			if (n == -1) {
				mec_x = j;
				mec_y = i;
			}
		}
	}

	for (int i = 0; i < T; i++) {
		expansion_dust();
		clean_dust();
	}
	
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++)
			if (vec[i][j] != -1 && vec[i][j] != 0)
				result += vec[i][j];
	}
	cout << result << endl;
	system("pause");
	return 0;
}