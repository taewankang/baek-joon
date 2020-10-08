//대각선이 위로만 갈 수 있는게 아니다.
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int dy[9] = {0, -1, -1, -1, 0, 0, 1, 1, 1};
int dx[9] = {0, 0, -1, 1, -1, 1, -1, 0, 1};
char map[9][8][8];
struct Person{int y, x;};
void input(){
    char c;
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) 
            cin >> map[0][i][j];
    }
}

void reset() {
    for(int i = 1; i <= 8; i++) {
        for(int j = 0; j < i; j++)
            for(int k = 0; k < 8; k++)
                map[i][j][k] = '.';
        for(int j = 0; j < 8 - i; j++) {
            for(int k = 0; k < 8; k++)
                map[i][i + j][k] = map[0][j][k];
        }
    }
}

int bfs() {
    queue<pair<Person, int>> q;
    q.push({{7, 0}, 0});
    while(!q.empty()) {
        int y = q.front().first.y;
        int x = q.front().first.x;
        int cnt = q.front().second;
        q.pop();
        if(map[cnt][y][x] == '#') continue;
        if(cnt == 8) return 1;
        for(int i = 0; i < 9; i++) {
            int nextY = y + dy[i];
            int nextX = x + dx[i];
            if(nextY < 0 || nextY > 7 || nextX < 0 || nextX > 7) continue;
            if(map[cnt][nextY][nextX] == '.')
                q.push({{nextY, nextX}, cnt + 1});
        }
    }
    return 0;
}

int main(void){
    input();
    reset();
    cout << bfs() << "\n";
    return 0;
}