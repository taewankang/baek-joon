1018
#include<iostream>
#include<string.h>
#include<string>
#include<algorithm>
using namespace std;
int M, N;
string black_first[8] = {	//검은 색이 먼저 칠해져 있을 때의 체스판
	{"BWBWBWBW"},
	{"WBWBWBWB"},
	{"BWBWBWBW"},
	{"WBWBWBWB"},
	{"BWBWBWBW"},
	{"WBWBWBWB"},
	{"BWBWBWBW"},
	{"WBWBWBWB"},
};

string white_first[8] = {	//흰 색이 먼저 칠해져 있을 때의 체스판
	{"WBWBWBWB"},
	{"BWBWBWBW"},
	{"WBWBWBWB"},
	{"BWBWBWBW"},
	{"WBWBWBWB"},
	{"BWBWBWBW"},
	{"WBWBWBWB"},
	{"BWBWBWBW"},
};

int whitefirst(int M, int N, string chess[]) {	//흰 색이 먼저 칠해져 있을 경우 다시 칠해야 하는 개수를 구한다.
	int res = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (chess[i + M][j + N] != white_first[i][j])
				res++;
		}
	}
	return res;
}

int blackfirst(int M, int N, string chess[]) {	//검은색이 먼저 칠해져 있을 경우 다시 칠해야 하는 개수를 구한다.
	int res = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (chess[i + M][j + N] != black_first[i][j])
				res++;
		}
	}
	return res;
}

int main(void) {
	cin >> M >> N;
	string color;
	string chess[51];
	int result = 9999;
	for( int i = 0; i< M; i++ ){
		cin >> color;
		chess[i] = color;
	}

	for (int i = 0; i < M - 7; i++) {
		for (int j = 0; j < N - 7; j++) {
			result = min(result, min(whitefirst(i, j, chess), blackfirst(i, j, chess)));	세 수중 최솟값을 구한다.
		}
	}
	cout << result << endl;
	system("pause");
	return 0;
}