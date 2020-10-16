/*
  상어가 움직이는 것과 동시에 vec벡터에 있는 상어 위치를 갱신해줬더니 문제가 발생
  => 4방향에 모두 냄새가 있을 경우 상어는 자신의 냄새가 있는 쪽으로 이동을 해야 하지만 실시간으로 상어 위치를 갱신해주면
  4방향을 확인하면서 앞의 상어의 먹이로 먹혀버린다. 이렇게 구현하면 안된다...
  상어를 모두 이동시킨 다음에 같은 위치에 다른 상어가 존재하는지 확인해서 상어의 정보를 지우는 방식으로 구현을 해야한다.
*/
#include <iostream>
#include <vector>
using namespace std;
int dy[5] = {0, -1, 1, 0, 0};
int dx[5] = {0, 0, 0, -1, 1};
struct Shark {
    int y, x, direction;
    vector < vector < int > > priority;
};
struct Block {
    int smell, num;
};
vector < vector < Block > > vec(21);
int N, M, K, sharkCnt;
vector < Shark > shark(401); 

Block pushBlock(int smell, int num) {
    Block block = {smell, num};
    return block;
}

void eraseShark(int idx) {
    sharkCnt--;
    shark[idx].y = 0;
    shark[idx].x = 0;
    shark[idx].direction = 0;
}

void sharkMove() {    
    for(int i = 1; i <= M; i++) {
        int y = shark[i].y;
        int x = shark[i].x;
        if(y == 0 && x == 0) continue;
        int direction = shark[i].direction;
        vector < vector < int > > priority = shark[i].priority;
        bool findSpace = false;
        for(int j = 1; j <= 4; j++) {
            int ny = y + dy[priority[direction][j]];
            int nx = x + dx[priority[direction][j]];
            if(ny < 1 || ny > N || nx < 1 || nx > N) continue;
            if(vec[ny][nx].smell) {    //냄새가 있으면 continue;
                continue;
            }
            findSpace = true;   //빈 공간을 찾았다.
            //방향을 확인할 때 상대가 돌아서 온 경우 이를 못 가는 곳이 아니라 먹히는 곳으로 판단을 해버린다.
            shark[i].y = ny;
            shark[i].x = nx;
            shark[i].direction = priority[direction][j];
            break;
        }
        if(findSpace == false) {    //빈 공간을 찾지 못했다면
            for(int j = 1; j <= 4; j++) {
                int ny = y + dy[priority[direction][j]];
                int nx = x + dx[priority[direction][j]];
                if(ny < 1 || ny > N || nx < 1 || nx > N) continue;
                if(vec[ny][nx].num == i) {
                    shark[i].y = ny;
                    shark[i].x = nx;
                    shark[i].direction = priority[direction][j];
                    break;
                }
            }
        }
    }
    for(int i = 1; i <= M; i++) {
        int y = shark[i].y;
        int x = shark[i].x;
        if(y == 0 && x == 0) continue;
        if(vec[y][x].num != i && shark[vec[y][x].num].y == y && shark[vec[y][x].num].x == x) {
            eraseShark(i);
        } else {
            vec[y][x].num = i;
            vec[y][x].smell = K;
        }
    }
}

void removeSmell() {    //상어 냄새 지우기
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            int n = vec[i][j].num;
            if(shark[n].y == i && shark[n].x == j) continue;
            if(vec[i][j].smell == 1) {
                vec[i][j].num = 0;
                vec[i][j].smell = 0;
            } else if(vec[i][j].smell) {
                vec[i][j].smell--;
            }
        }
    }
}

int main(void){
    cin >> N >> M >> K;
    sharkCnt = M;   //남은 상어의 수를 저장
    int n;
    for(int i = 1; i <= N; i++) {
        vec[i].push_back(pushBlock(0, 0));
        for(int j = 1; j <= N; j++) {
            cin >> n;
            if(n != 0) {
                vec[i].push_back(pushBlock(K, n));
                shark[n].y = i;
                shark[n].x = j;
            } else {
                vec[i].push_back(pushBlock(0, n));
            }
        }
    }
    for(int i = 1; i <= M; i++) {
        cin >> n;
        shark[i].direction = n;
    }

    for(int i = 1; i <= M; i++) {
        vector < vector < int > > priority(5);
        for(int j = 1; j <= 4; j++) {
            priority[j].push_back(0);
            for(int k = 1; k <= 4; k++) {
                cin >> n;
                priority[j].push_back(n);
            }
        }
        shark[i].priority = priority;
    }
    int idx = 0;
    while(sharkCnt != 1) {
        sharkMove();
        removeSmell();
        if(idx >= 1000) {
            idx = -1;
            break;
        }
        idx++;
    }
    cout << idx << endl;
    //1000초가 넘으면 -1을 출력
    return 0;
}