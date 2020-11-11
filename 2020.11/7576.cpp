#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N, M, H;
int map[101][101][101] = { 0, };
int tomatoCnt = 0;
struct Dir {int h, y, x;};
Dir dir[6] = {{1, 0, 0}, {-1, 0, 0}, {0, 1, 0}, {0, -1, 0}, {0, 0, 1}, {0, 0, -1}};

int bfs() {
    int answer = 0;
    queue<pair<Dir, int>> q;
    for(int i = 1; i <= H; i++) 
        for(int j = 1; j <= M; j++) 
            for(int k = 1; k <= N; k++) 
                if(map[i][j][k] == 1) q.push({{i, j, k}, 0});

    while(!q.empty()) {
        int h = q.front().first.h;
        int y = q.front().first.y;
        int x = q.front().first.x;
        int day = q.front().second;
        if(answer < day) answer = day;
        q.pop();
        if(map[h][y][x] == 1) {
            for(int l = 0; l < 6; l++) {
                int nh = h + dir[l].h;
                int ny = y + dir[l].y;
                int nx = x + dir[l].x;
                if(nh < 1 || nh > H || ny < 1 || ny > M || nx < 1 || nx > N) continue;
                if(map[nh][ny][nx] == 0) {
                    map[nh][ny][nx] = 1;
                    tomatoCnt--;
                    q.push({{nh, ny, nx}, day + 1});
                }
            }
        }
    }
    if(tomatoCnt != 0) return -1;
    return answer;
}

int main(void) {
    cin >> N >> M >> H;
    //M: 세로 N: 가로
    int n;
    for(int h = 1; h <= H; h++) {
        for(int i = 1; i <= M; i++) {
            for(int j = 1; j <= N; j++) {
                cin >> n;
                map[h][i][j] = n;
                if(n == 0) tomatoCnt++;
            }
        }
    }

    if(tomatoCnt == 0) {
        cout << "0\n";
        return 0;
    }

    cout << bfs() << endl;
    return 0;
}