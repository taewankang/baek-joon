#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N, M;
struct Ball{int y, x;};
struct UnionBall {Ball red, blue;};
Ball goal;
vector<vector<char>> map(11);

UnionBall moveUp(Ball red, Ball blue) {
    //위로 기울이기 위해서는 red.y와 blue.y를 비교해야 된다.
    UnionBall unionBall;
    if(red.y > blue.y) {        //blue가 먼저 이동해야 된다.
        while(1) {
            int ny = blue.y - 1;
            int nx = blue.x;
            if(map[ny][nx] == '#') break;
            else if(ny == goal.y && nx == goal.x) { //파란 구슬이 통과한다.
                blue.y = goal.y;
                blue.x = goal.x;
                break;
            } else blue.y--;
        }
        while(1) {
            int ny = red.y - 1;
            int nx = red.x;
            if(map[ny][nx] == '#') break;
            else if(ny == goal.y && nx == goal.x) {
                red.y = goal.y;
                red.x = goal.x;
                break;
            } else if(ny == blue.y && nx == blue.x) break;
            else red.y--;
        }
    } else {    //red가 먼저 이동해야 된다.
        while(1) {
            int ny = red.y - 1;
            int nx = red.x;
            if(map[ny][nx] == '#') break;
            else if(ny == goal.y && nx == goal.x) { //파란 구슬이 통과한다.
                red.y = goal.y;
                red.x = goal.x;
                break;
            } else red.y--;
        }
        while(1) {
            int ny = blue.y - 1;
            int nx = blue.x;
            if(map[ny][nx] == '#') break;
            else if(ny == goal.y && nx == goal.x) {
                blue.y = goal.y;
                blue.x = goal.x;
                break;
            } else if(ny == red.y && nx == red.x) break;
            else blue.y--;
        }
    }
    unionBall = {red, blue};
    return unionBall;
}

UnionBall moveDown(Ball red, Ball blue) {
    UnionBall unionBall;
    if(red.y < blue.y) {        //blue가 먼저 이동해야 된다.
        while(1) {
            int ny = blue.y + 1;
            int nx = blue.x;
            if(map[ny][nx] == '#') break;
            else if(ny == goal.y && nx == goal.x) { //파란 구슬이 통과한다.
                blue.y = goal.y;
                blue.x = goal.x;
                break;
            } else blue.y++;
        }
        while(1) {
            int ny = red.y + 1;
            int nx = red.x;
            if(map[ny][nx] == '#') break;
            else if(ny == goal.y && nx == goal.x) {
                red.y = goal.y;
                red.x = goal.x;
                break;
            } else if(ny == blue.y && nx == blue.x) break;
            else red.y++;
        }
    } else {    //red가 먼저 이동해야 된다.
        while(1) {
            int ny = red.y + 1;
            int nx = red.x;
            if(map[ny][nx] == '#') break;
            else if(ny == goal.y && nx == goal.x) { //파란 구슬이 통과한다.
                red.y = goal.y;
                red.x = goal.x;
                break;
            } else red.y++;
        }
        while(1) {
            int ny = blue.y + 1;
            int nx = blue.x;
            if(map[ny][nx] == '#') break;
            else if(ny == goal.y && nx == goal.x) {
                blue.y = goal.y;
                blue.x = goal.x;
                break;
            } else if(ny == red.y && nx == red.x) break;
            else blue.y++;
        }
    }
    unionBall = {red, blue};
    return unionBall;
}

UnionBall moveLeft(Ball red, Ball blue) {
    UnionBall unionBall;
    if(red.x < blue.x) {    //red먼저 이동시킨다.
        while(1) {
            int ny = red.y;
            int nx = red.x - 1;
            if(map[ny][nx] == '#') break;
            else if(ny == goal.y && nx == goal.x) {
                red.y = goal.y;
                red.x = goal.x;
                break;
            } else red.x--;
        }
        while(1) {
            int ny = blue.y;
            int nx = blue.x - 1;
            if(map[ny][nx] == '#') break;
            else if(ny == goal.y && nx == goal.x) {
                blue.y = goal.y;
                blue.x = goal.x;
                break;
            } else if(ny == red.y && nx == red.x) break;
            else blue.x--;
        }
    } else {    //blue먼저 이동시킨다.
        while(1) {
            int ny = blue.y;
            int nx = blue.x - 1;
            if(map[ny][nx] == '#') break;
            else if(ny == goal.y && nx == goal.x) {
                blue.y = goal.y;
                blue.x = goal.x;
                break;
            } else blue.x--;
        }
        while(1) {
            int ny = red.y;
            int nx = red.x - 1;
            if(map[ny][nx] == '#') break;
            else if(ny == goal.y && nx == goal.x) {
                red.y = goal.y;
                red.x = goal.x;
                break;
            } else if(ny == blue.y && nx == blue.x) break;
            else red.x--;
        }
    }
    unionBall = {red, blue};
    return unionBall;
}

UnionBall moveRight(Ball red, Ball blue) {
    UnionBall unionBall;
    if(red.x > blue.x) {    //red먼저 이동시킨다.
        while(1) {
            int ny = red.y;
            int nx = red.x + 1;
            if(map[ny][nx] == '#') break;
            else if(ny == goal.y && nx == goal.x) {
                red.y = goal.y;
                red.x = goal.x;
                break;
            } else red.x++;
        }
        while(1) {
            int ny = blue.y;
            int nx = blue.x + 1;
            if(map[ny][nx] == '#') break;
            else if(ny == goal.y && nx == goal.x) {
                blue.y = goal.y;
                blue.x = goal.x;
                break;
            } else if(ny == red.y && nx == red.x) break;
            else blue.x++;
        }
    } else {    //blue먼저 이동시킨다.
        while(1) {
            int ny = blue.y;
            int nx = blue.x + 1;
            if(map[ny][nx] == '#') break;
            else if(ny == goal.y && nx == goal.x) {
                blue.y = goal.y;
                blue.x = goal.x;
                break;
            } else blue.x++;
        }
        while(1) {
            int ny = red.y;
            int nx = red.x + 1;
            if(map[ny][nx] == '#') break;
            else if(ny == goal.y && nx == goal.x) {
                red.y = goal.y;
                red.x = goal.x;
                break;
            } else if(ny == blue.y && nx == blue.x) break;
            else red.x++;
        }
    }
    unionBall = {red, blue};
    return unionBall;
}

bool check(Ball red, Ball blue, int cnt) {
    if(red.y == goal.y && red.x == goal.x && blue.y == goal.y && blue.x == goal.x) {    //파랑, 빨강이 모두 통과 했다면
        return false;    
    } else if(red.y == goal.y && red.x == goal.x) {     //빨간색만 통과 했다면
        cout << cnt << endl;
        exit(0);
    } else if(blue.y == goal.y && blue.x == goal.x) {    //파란색만 통과했다면
        return false;
    } return true;
}

void bfs(UnionBall unionBall) {
    queue<pair<UnionBall, int>> q;
    q.push({unionBall, 1});
    while(!q.empty()) {
        Ball red = q.front().first.red;
        Ball blue = q.front().first.blue;
        int cnt = q.front().second;
        q.pop();
        if(cnt > 10) break;
        UnionBall up = moveUp(red, blue);
        UnionBall down = moveDown(red, blue);
        UnionBall left = moveLeft(red, blue);
        UnionBall right = moveRight(red, blue);

        if(!(red.y == up.red.y && red.x == up.red.x && blue.y == up.blue.y && blue.x == up.blue.x)) { //움직였다면
            if(check(up.red, up.blue, cnt)) q.push({up, cnt + 1});
        }
        if(!((red.y == down.red.y && red.x == down.red.x) && (blue.y == down.blue.y && blue.x == down.blue.x))) {
            if(check(down.red, down.blue, cnt)) q.push({down, cnt + 1});
        }
        if(!((red.y == left.red.y && red.x == left.red.x) && (blue.y == left.blue.y && blue.x == left.blue.x))) {
            if(check(left.red, left.blue, cnt)) q.push({left, cnt + 1});
        }
        if(!((red.y == right.red.y && red.x == right.red.x) && (blue.y == right.blue.y && blue.x == right.blue.x))) {
            if(check(right.red, right.blue, cnt)) q.push({right, cnt + 1});
        }
    }
}

int main(void){
    cin >> N >> M;

    for(int i = 1; i <= N; i++) {
        vector<char> temp(M + 1);
        map[i] = temp;
    }
    UnionBall unionBall;
    char c;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            cin >> c;
            if(c == 'R') {
                unionBall.red = {i, j};
                map[i][j] = '.';
            } else if(c == 'B') {
                unionBall.blue = {i, j};
                map[i][j] = '.';
            } else if(c == 'O') {   //.로 초기화 했는데 일단...
                goal = {i, j};
                map[i][j] = '.';
            } else map[i][j] = c;
        }
    }
    bfs(unionBall);
    cout << -1 << endl;
    return 0;
}