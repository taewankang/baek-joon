#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Mal {int y, x, direction;};
vector < vector < int > > vec(13);
vector < Mal > mal;
int dy[5] = {0, 0, 0, -1, 1};
int dx[5] = {0, 1, -1, 0, 0};
int N, K;
int map[11][13][13] = {0, };
Mal makeMal(int y, int x, int direction) {
    Mal mal = {y, x, direction};
    return mal;
}

int lastMal(int y, int x) { //말의 개수 위를 출력
    int idx = 1;
    while(1) {
        if(map[idx][y][x] == 0) return idx;
        else idx++;
    }
    return 1;
}

bool check() {      //한 위치에 4개 이상 올려져 있는지 확인한다.
    for(int i = 1; i <= N; i++) 
        for(int j = 1; j <= N; j++) 
            if(lastMal(i, j) > 4) return true;
    return false;
}

void moveMal(int by, int bx, int ay, int ax) {
    //before에 있는 말들을 after로 바꿔준다.
    //before에 있는 mal변수들도 다 바꿔준다.
    int topIdx = lastMal(ay, ax);
    int idx = 1;
    while(1) {
        if(map[idx][by][bx] == 0) break;
        int cnt = map[idx][by][bx];
        mal[cnt].y = ay; mal[cnt].x = ax;
        map[topIdx++][ay][ax] = map[idx][by][bx];
        map[idx][by][bx] = 0;
        idx++;
    }
}

void turnDirection(int direction, int cnt) {    //방향을 뒤집어 주는 함수
    if(mal[cnt].direction == 1) mal[cnt].direction = 2;
    else if(mal[cnt].direction == 2) mal[cnt].direction = 1;
    else if(mal[cnt].direction == 3) mal[cnt].direction = 4;
    else if(mal[cnt].direction == 4) mal[cnt].direction = 3;
}

void redBlock(int y, int x, int ny, int nx, int cnt) {
    vector < int > temp;
    int idx = 1;
    while(1) {
        if(map[idx][y][x] == 0) break;
        temp.push_back(map[idx][y][x]);
        idx++;
    }
    reverse(temp.begin(), temp.end());
    for(int i = 0; i < temp.size(); i++) map[i + 1][y][x] = temp[i];
    moveMal(y, x, ny, nx);
}

void whiteBlock(int y, int x, int ny, int nx) {
    moveMal(y, x, ny, nx);
}

void blueBlock(int y, int x, int direction, int cnt) {
    //다음으로 움직일 y, x, 현재방향 direction, 말의 인덱스 번호
    //해당 말이 가장 아래에 있고 다음 말이 파랑이거나 범위 바깥이라면
    //방향을 바꿔준다.
    turnDirection(direction, cnt);
    int ny = y + dy[mal[cnt].direction];
    int nx = x + dx[mal[cnt].direction];
    if(ny < 1 || ny > N || nx < 1 || nx > N || vec[ny][nx] == 2) return;
    //범위를 넘어가면 이동하면 안된다.
    if(vec[ny][nx] == 0) whiteBlock(y, x, ny, nx);
    else if(vec[ny][nx] == 1) redBlock(y, x, ny, nx, cnt);
}

void move() {
    for(int i = 1; i <= K; i++) {
        int y = mal[i].y;
        int x = mal[i].x;
        if(map[1][y][x] != i) continue; //제일 아래에 있는 말이 아니라면
        int direction = mal[i].direction;
        int ny = y + dy[direction];
        int nx = x + dx[direction];
        if(ny < 1 || ny > N || nx < 1 || nx > N || vec[ny][nx] == 2) blueBlock(y, x, direction, i);
        else if(vec[ny][nx] == 0) whiteBlock(y, x, ny, nx); //흰색이라면
        else if(vec[ny][nx] == 1) redBlock(y, x, ny, nx, i); //빨강이라면
    }
}

int main(void){
    cin >> N >> K;
    int n, answer = 1;
    for(int i = 1; i <= N; i++) {
        vec[i].push_back(0);
        for(int j = 1; j <= N; j++) {
            cin >> n;
            vec[i].push_back(n);
        }
    }

    int a, b, c;
    mal.push_back(makeMal(0, 0, 0));
    for(int i = 1; i <= K; i++) {
        cin >> a >> b >> c;
        mal.push_back(makeMal(a, b, c));
        int idx = 1;
        while(1) {
            if(map[idx][a][b] == 0) { //map위에 말이 없다면
                map[idx][a][b] = i;
                break;
            } else idx++;
        }
    }
    while(1) {
        move();
        if(check()) break;
        if(answer > 1000) {
            answer = -1;
            break;
        }
        answer++;
    }
    cout << answer << endl;
    return 0;
}