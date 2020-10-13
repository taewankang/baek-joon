#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
int N, L;
vector < vector < int > > map(101);

bool isRowValid(int idx, bool isRow) {
    vector < int > temp;
    vector<bool> check(101, false);
    if(isRow) for(int i = 1; i <= N; i++)  temp.push_back(map[i][idx]);
    else for(int i = 1; i <= N; i++) temp.push_back(map[idx][i]);
    for(int i = 1; i < N; i++) {
        if(abs(temp[i] - temp[i - 1]) > 1) return false;
        else if(temp[i] - temp[i - 1] == -1) {   //앞이 더 크다면 오르막길 장애물 설치
            if(i + L - 1 >= N) return false;
            for(int j = i; j <= i + L - 1; j++) {
                if(check[j] || temp[i] != temp[j]) return false;
                check[j] = true;
            }
        } else if(temp[i] - temp[i - 1] == 1) {    //뒤가 더 크다면 내리막길 장애물 설치
            if(i - L < 0) return false;
            for(int j = i - L; j <= i - 1; j++) {
                if(check[j] || temp[i - 1] != temp[j]) return false;
                check[j] = true;
            }
        }
    }
    return true;
}

int main(void){
    cin >> N >> L;
    int n, answer = 0;
    for(int i = 1; i <= N; i++) {
        map[i].push_back(0);
        for(int j = 1; j <= N; j++) {
            cin >> n;
            map[i].push_back(n);
        }
    }    

    for(int i = 1; i <= N; i++) {
        if(isRowValid(i, true)) answer++;
        if(isRowValid(i, false)) answer++;
    }
    cout << answer << endl;
    return 0;
}