//새로운 게임2
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int map[13][13] = {0, };
int malMap[11][13][13] = {0, };
int N, K;
int dy[5] = {0, 0, 0, -1, 1};
int dx[5] = {0, 1, -1, 0, 0};
struct Mal {int y, x, direction;};
vector < Mal > mal;
int cnt = 0;

Mal pushMal(int y, int x, int direction) {
    Mal mal = {y, x, direction};
    return mal;
}

void moveMal(int by, int bx, int ay, int ax, int idx, bool isRed) {
    vector < int > temp;
    int h = 1;
    bool start = false;
    while(1) {  //idx위에 있는 말들을 temp배열에 복사
        if(h > 10) break;
        if(malMap[h][by][bx] == idx) start = true;
        if(start && malMap[h][by][bx]) {
            temp.push_back(malMap[h][by][bx]);
            malMap[h][by][bx] = 0;
        }
        h++;
    }
    if(isRed) reverse(temp.begin(), temp.end());  //빨간칸으로 이동하는거면 뒤집어서 이동해야 한다.
    start = false;
    h = 1, idx = 0;
    while(1) {  //복사한 데이터를 옮긴 자리에 복사
        if(idx == temp.size()) break;
        if(malMap[h][ay][ax] == 0) start = true;
        if(start) {
            malMap[h][ay][ax] = temp[idx];
            mal[temp[idx]].y = ay;
            mal[temp[idx]].x = ax;            
            idx++;
        }
        h++;
    }
}

void changeDirection(int idx) {
    if(mal[idx].direction == 1) mal[idx].direction = 2;
    else if(mal[idx].direction == 2) mal[idx].direction = 1;
    else if(mal[idx].direction == 3) mal[idx].direction = 4;
    else if(mal[idx].direction == 4) mal[idx].direction = 3;
}

void whiteBlock(int by, int bx, int ay, int ax, int idx) {
    moveMal(by, bx, ay, ax, idx, false);
}

void redBlock(int by, int bx, int ay, int ax, int idx) {
    moveMal(by, bx, ay, ax, idx, true);
}

void blueBlock(int y, int x, int idx) {
    changeDirection(idx);
    int direction = mal[idx].direction;
    int ny = y + dy[direction];
    int nx = x + dx[direction];
    if(ny < 1 || ny > N || nx < 1 || nx > N) return;
    if(map[ny][nx] == 0) whiteBlock(y, x, ny, nx, idx);
    else if(map[ny][nx] == 1) redBlock(y, x, ny, nx, idx);
}

bool check() {
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            int h = 1, cnt = 0;
            while(1) {
                if(malMap[h][i][j] != 0) cnt++;
                else break;
                h++;
            }
            if(cnt >= 4) return true;
        }
    }
    return false;
}

void moveMal() {
    for(int i = 1; i <= K; i++) {
        int y = mal[i].y;
        int x = mal[i].x;
        int direction = mal[i].direction;
        int ny = y + dy[direction];
        int nx = x + dx[direction];
        if(ny < 1 || ny > N || nx < 1 || nx > N || map[ny][nx] == 2) blueBlock(y, x, i);
        else if(map[ny][nx] == 0) whiteBlock(y, x, ny, nx, i);  //흰색으로 이동
        else if(map[ny][nx] == 1) redBlock(y, x, ny, nx, i);    //빨간색으로 이동
        if(check()) {
            cout << cnt << endl;
            exit(0);
        }
    }
}

int main(void){
    cin >> N >> K;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            cin >> map[i][j];
        }
    }

    int a, b, c;
    mal.push_back(pushMal(0, 0, 0));
    for(int i = 1; i <= K; i++) {
        cin >> a >> b >> c;
        malMap[1][a][b] = i;
        mal.push_back(pushMal(a, b, c));
    }

    while(1) {
        cnt++;
        moveMal();
        if(cnt > 1000) {
            cnt = -1;
            break;
        }
    }
    cout << cnt << endl;
    return 0;
}