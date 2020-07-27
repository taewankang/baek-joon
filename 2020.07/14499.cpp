#include<iostream>
#include<vector>
using namespace std;
int dice[4][3] = {0, };
int map[21][21];
struct Loc{ int y, x; };
struct Dir{int y, x;};
Loc l;
vector<int> order;
Dir dir[5] = {{0, 0}, {0, 1}, {0, -1}, {-1, 0}, {1, 0}};
int N, M, K, k;

/*
    이동한 칸에 쓰여 있는 수가 0이면, 주사위의 바닥면에 쓰여 있는 수가 칸에 복사된다.
    0이 아닌 경우에는 칸에 쓰여 있는 수가 바닥면으로 복사되며, 칸에 쓰여 있는 수는 0이 된다.
*/
void copy_map(){
    if(map[l.y][l.x] == 0)
        map[l.y][l.x] = dice[1][1];
    else {
        dice[1][1] = map[l.y][l.x];
        map[l.y][l.x] = 0;
    }
    cout << dice[3][1] << endl;
}

//북쪽으로 이동
void move_north(int temp[][3]){
    temp[1][1] = dice[0][1];
    temp[2][1] = dice[1][1];
    temp[3][1] = dice[2][1];
    temp[0][1] = dice[3][1];
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 3; j++)
            dice[i][j] = temp[i][j];
    }
    copy_map();
}

//남쪽으로 이동
void move_south(int temp[][3]){
    temp[3][1] = dice[0][1];
    temp[0][1] = dice[1][1];
    temp[1][1] = dice[2][1];
    temp[2][1] = dice[3][1];
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 3; j++)
            dice[i][j] = temp[i][j];
    }
    copy_map();
}

//동쪽으로 이동
void move_east(int temp[][3]){
    temp[3][1] = dice[1][0];
    temp[1][0] = dice[1][1];
    temp[1][1] = dice[1][2];
    temp[1][2] = dice[3][1];
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 3; j++)
            dice[i][j] = temp[i][j];
    }
    copy_map();
}

//서쪽으로 이동
void move_west(int temp[][3]){
    temp[1][1] = dice[1][0];
    temp[1][2] = dice[1][1];
    temp[3][1] = dice[1][2];
    temp[1][0] = dice[3][1];
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 3; j++)
            dice[i][j] = temp[i][j];
    }
    copy_map();
}

void move(int cnt){
    int temp[4][3] = {0, };
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 3; j++)
            temp[i][j] = dice[i][j];
    }
    if(cnt == 1) move_east(temp);
    else if(cnt == 2) move_west(temp);
    else if(cnt == 3) move_north(temp);
    else if(cnt == 4) move_south(temp);
}

void verify_location(){
    for(int i = 0; i < order.size(); i++){
        if(l.y + dir[order[i]].y >= 0 &&
            l.y + dir[order[i]].y < N &&
            l.x + dir[order[i]].x >= 0 &&
            l.x + dir[order[i]].x < M){
            l.y += dir[order[i]].y;
            l.x += dir[order[i]].x;
            move(order[i]);
        }
    }
}

int main(void) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> N >> M >> l.y >> l.x >> K;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++)
            cin >> map[i][j];
    }

    for(int i = 0; i < K; i++){
        cin >> k;
        order.push_back(k);
    }
    verify_location();
    return 0;
}
