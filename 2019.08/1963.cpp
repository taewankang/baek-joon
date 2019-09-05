#include<iostream>
#include<math.h>
#include<vector>
#include<queue>
using namespace std;
vector<bool> vec(10001, false);
bool check[10001];
void make_prime_vector() {
	int i = 2;
	for (int j = 1000; j < 10001; j++) {
		for (i = 2; i <= (int)sqrt(j); i++) 
			if (j % i == 0)
				break;
		if (i == (int)(sqrt(j) + 1))
			vec[j] = true;
	}
}

int thousand_change(int num, int i) {
	num %= 1000;
	num += i * 1000;
	return num;
}

int hundred_change(int num, int i) {
	int temp = num / 1000;
	num %= 100;
	num += temp * 1000;
	num += i * 100;
	return num;
}

int ten_change(int num, int i) {
	int temp1 = num / 1000;
	num %= 1000;
	int temp2 = num / 100;
	num %= 10;
	num += temp1 * 1000;
	num += temp2 * 100;
	num += i * 10;
	return num;
}

int one_change(int num, int i) {
	num /= 10;
	num *= 10;
	num += i;
	return num;
}

int bfs(int A, int B) {
	if (A == B) {
		cout << "0\n";
		return 0;
	}
	queue<pair<int, int>> q;
	q.push({ A, 0 });
	while (!q.empty()) {
		int fir = q.front().first;
		int sec = q.front().second;
		q.pop();
		if (fir == B) {
			cout << sec << "\n";
			return 0;
		}
		for (int i = 1; i < 10; i++) {
			int th = thousand_change(fir, i);
			if (vec[th] == true && check[th]== false) {
				q.push({ th, sec + 1 });
				check[th] = true;
			}
		}
		for (int i = 0; i < 10; i++) {
			int hun = hundred_change(fir, i);
			if (vec[hun] == true && check[hun] == false) {
				q.push({ hun, sec + 1 });
				check[hun] = true;
			}
		}
		for (int i = 0; i < 10; i++) {
			int ten = ten_change(fir, i);
			if (vec[ten] == true && check[ten] == false) {
				q.push({ ten, sec + 1 });
				check[ten] = true;
			}
		}
		for (int i = 0; i < 5; i++) {
			int one = one_change(fir, i * 2 + 1);
			if (vec[one] == true && check[one] == false) {
				q.push({ one, sec + 1 });
				check[one] = true;
			}
		}
	}
	return -1;
}


int main(void) {
	int T;
	cin >> T;
	make_prime_vector();
	for (int i = 0; i < T; i++) {
		for (int i = 1000; i < 10001; i++)
			check[i] = false;
		int A, B;
		cin >> A >> B;
		if (bfs(A, B) == -1)
			cout << "Impossible\n";		
	}
	system("pause");
	return 0;
}