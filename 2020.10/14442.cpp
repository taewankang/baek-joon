#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int N, M, K;
vector<vector<int>> map(1001);
int visit[11][1001][1001] = {0, };
struct Location {int k, y, x;};
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};

void bfs() {
    queue<pair<Location, int>> q;
    q.push({{K, 1, 1}, 1});
    visit[K][1][1] = 1;
    while(!q.empty()) {
        int k = q.front().first.k;
        int y = q.front().first.y;
        int x = q.front().first.x;
        int cnt = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++) {
            int nextY = y + dy[i];
            int nextX = x + dx[i];
            if(nextY < 1 || nextY > N || nextX < 1 || nextX > M) 
                continue;
            if(!visit[k][nextY][nextX] && map[nextY][nextX] == '0') {
                visit[k][nextY][nextX] = cnt + 1;
                q.push({{k, nextY, nextX}, cnt + 1});
            } else if(k && !visit[k - 1][nextY][nextX] && map[nextY][nextX] == '1') {
                visit[k - 1][nextY][nextX] = cnt + 1;
                q.push({{k - 1, nextY, nextX}, cnt + 1});
            }
        }
    }
}

int main(void){
    cin >> N >> M >> K;
    char c;
    for(int i = 1; i <= N; i++) {
        map[i].push_back(' ');
        for(int j = 1; j <= M; j++) {
            cin >> c;
            map[i].push_back(c);
        }
    }
    bfs();
    int answer = 123456789;
    for(int i = 0; i <= K; i++) {
        if(visit[i][N][M] != 0 && answer > visit[i][N][M]) 
            answer = visit[i][N][M];
    }
    if(answer == 123456789) answer = -1;
    cout << answer << endl;
    return 0;
}