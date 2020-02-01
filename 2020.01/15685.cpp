#include<iostream>
#include<vector>
using namespace std;
bool arr[202][202] = { false, };
int result = 0;
class Dir {
public:
	int x, y;
};
Dir direction[4] = { {1, 0}, {0, -1}, {-1, 0}, {0, 1} };		//x, y

void check() {
	for (int i = 0; i < 201; i++) {
		for (int j = 0; j < 201; j++) {
			if (arr[i][j]) {
				if (arr[i][j + 1] == true && arr[i + 1][j] == true && arr[i + 1][j + 1] == true)
					result++;
			}
		}
	}
}

void draw(int y, int x, int d, int g) {
	int cnt = 0;
	vector<int> vec;
	vec.push_back(d);
	while (1) {
		if (cnt++ == g)
			break;
		int s = vec.size();
		for (int i = s - 1; i >= 0; i--)
			vec.push_back((vec[i] + 1) % 4);
	}

	for (int i = 0; i < vec.size(); i++) {
		switch (vec[i]) {
		case 0:
			arr[y][x] = true;
			y += direction[0].y;
			x += direction[0].x;
			arr[y][x] = true;
			break;
		case 1:
			arr[y][x] = true;
			y += direction[1].y;
			x += direction[1].x;
			arr[y][x] = true;
			break;
		case 2:
			arr[y][x] = true;
			y += direction[2].y;
			x += direction[2].x;
			arr[y][x] = true;
			break;
		case 3:
			arr[y][x] = true;
			y += direction[3].y;
			x += direction[3].x;
			arr[y][x] = true;
			break;
		}
	}
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int N, x, y, d, g;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x >> y >> d >> g;
		draw(y + 100, x + 100, d, g);
	}
	check();
	cout << result << endl;
	system("pause");
	return 0;
}