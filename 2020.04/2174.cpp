#include<iostream>
#include<vector>
using namespace std;
int A, B, N, M;
int map[101][101] = { 0, };
struct Robot {
	int y, x, d;
};

struct Dir {
	int y, x;
};

Robot robot[101];
Dir dir[4] = { {0, 1}, {-1, 0}, {0, -1}, {1, 0} };	//E N W S

void decide_direction(int num, char c) {	//ó�� �Է¹��� �� ���ڸ� ���ڷ� ���������ش�.
	if (c == 'E')
		robot[num].d = 0;
	else if (c == 'N')
		robot[num].d = 1;
	else if (c == 'W')
		robot[num].d = 2;
	else if (c == 'S')
		robot[num].d = 3;
}

void move_forward(int num) {	//�ٶ󺸴� �������� ��ĭ �����̴� �Լ�
	robot[num].y += dir[robot[num].d].y;
	robot[num].x += dir[robot[num].d].x;
}

bool move(int num, char d, int cnt) {
	if (d == 'F') {
		map[robot[num].y][robot[num].x] = 0;	//�κ��� �����̱� ���� map���� �����ش�.
		for (int i = 0; i < cnt; i++) {
			move_forward(num);	//�ٶ󺸴� �������� 1ĭ �����δ�.
			if (map[robot[num].y][robot[num].x]) {	//�ٸ� �κ��̶� �浹�� ���
				cout << "Robot " << num << " crashes into robot " << map[robot[num].y][robot[num].x] << endl;
				return false;
			}
			else if (robot[num].y < 1 || robot[num].y > B || robot[num].x < 1 || robot[num].x > A) {	//���� �浹�� ���
				cout << "Robot " << num << " crashes into the wall\n";
				return false;
			}
		}
		map[robot[num].y][robot[num].x] = num;
	}
	else if (d == 'R') {
		cnt %= 4;
		robot[num].d += 4 - cnt;
		robot[num].d %= 4;
	}
	else if (d == 'L') {
		robot[num].d += cnt;
		robot[num].d %= 4;
	}
	return true;
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> A >> B >> N >> M;
	int y, x, num, cnt;
	char d;
	for (int i = 1; i <= N; i++) {
		cin >> x >> y >> d;
		robot[i].y = B - y + 1;		//������ �ִ� (1, 1)�� map�迭���� (B - y + 1, x)�� ǥ����
		robot[i].x = x;
		decide_direction(i, d);
		map[B - y + 1][x] = i;
	}


	for (int i = 0; i < M; i++) {
		cin >> num >> d >> cnt;
		if (!move(num, d, cnt))	//�κ��� �����̴µ� �ɸ��°� ������
			break;
		else if (i == M - 1)	//�κ��� �����̴µ� �ɸ��°� ���ٸ�
			cout << "OK\n";
	}

	system("pause");
	return 0;
}