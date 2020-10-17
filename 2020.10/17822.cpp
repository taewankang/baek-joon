//원판 돌리기
#include <iostream>
#include <vector>
using namespace std;
vector < vector < int > > map(51);
int N, M, T;

void turnClock(int x) {
    vector < int > temp;
    temp.push_back(map[x][M]);
    for(int i = 1; i < M; i++) temp.push_back(map[x][i]);
    for(int i = 0; i < temp.size(); i++) map[x][i + 1] = temp[i];
}

void turnReverseClock(int x) {
    vector < int > temp;
    for(int i = 2; i <= M; i++) temp.push_back(map[x][i]);
    temp.push_back(map[x][1]);
    for(int i = 0; i < temp.size(); i++) map[x][i + 1] = temp[i];
}

bool erase() {
    bool isErase = false;
    vector < vector < int > > temp = map;
    for(int i = 1; i <= N; i++) {
        if(map[i][1] != -1 && map[i][1] == map[i][M]) {
            temp[i][1] = -1;
            temp[i][M] = -1;
            isErase = true;
        }
        for(int j = 1; j < M; j++) {
            if(map[i][j] != -1 && map[i][j] == map[i][j + 1]) {
                temp[i][j] = -1;
                temp[i][j + 1] = -1;
                isErase = true;
            }
        }
    }

    for(int i = 1; i <= M; i++) {
        for(int j = 1; j < N; j++) {
            if(map[j][i] != -1 && map[j][i] == map[j + 1][i]) {
                temp[j][i] = -1;
                temp[j + 1][i] = -1;
                isErase = true;
            }
        }
    }

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) 
            map[i][j] = temp[i][j];
    }    
    return isErase;
}

void eraseFail() {
    int sum = 0, idx = 0;
    double aver = 0;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            if(map[i][j] != -1) {
                sum += map[i][j];
                idx++;
            }
        }
    }
    aver = (double)sum / idx;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            if(map[i][j] != -1 && map[i][j] < aver) map[i][j] += 1;
            else if(map[i][j] != -1 && map[i][j] > aver) map[i][j] -= 1;
        }
    }    
}

void rotate(int x, int d, int k) {
    if(d == 0) {
        for(int i = 1; i * x <= N; i++)
            for(int j = 0; j < k; j++) {
                turnClock(i * x);
            }
    } else {
        for(int i = 1; i * x <= N; i++) {
            for(int j = 0; j < k; j++) 
                turnReverseClock(i * x);
        }
    }    //시계 반대
    if(!erase()) eraseFail();
}

int main(void){
    cin >> N >> M >> T;
    int n;
    for(int i = 1; i <= N; i++) {
        map[i].push_back(0);
        for(int j = 1; j <= M; j++) {
            cin >> n;
            map[i].push_back(n);
        }
    }
    int x, d, k;
    for(int i = 0; i < T; i++) {
        cin >> x >> d >> k;
        rotate(x, d, k);
    }
    int answer = 0;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            if(map[i][j] != -1)
                answer += map[i][j];        
        }
    }
    cout << answer << endl;
    return 0;
}