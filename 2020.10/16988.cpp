//Baaaaaaaaaduk2 (Easy) 
/*
    돌 2개를 놓아 상대 돌을 최대한 많이 죽이는 위치를 찾아라
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};
int N, M;
struct Blank{int y, x;};
vector<Blank> blank;
vector<vector<int>> vec(21);
bool visit[21][21] = {false, };
int answer = 0;
int bfs(int i, int j) {
    queue<pair<int, int>> q;
    q.push({i, j});
    visit[i][j] = true;
    bool fail = false;
    int cnt = 1;
    while(!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++) {
            int nextY = y + dy[i];
            int nextX = x + dx[i];
            if(nextY < 1 || nextY > N || nextX < 1 || nextX > M) continue;
            if(vec[nextY][nextX] == 0) fail = true;
            if(vec[nextY][nextX] == 2 && !visit[nextY][nextX]) {
                visit[nextY][nextX] = true;
                q.push({nextY, nextX});
                cnt++;
            }
        }
    }
    if(fail) return 0;
    return cnt;
}

void selectLocation(int i, int j) { //모든 경우의 수 배치 완료
    vec[blank[i].y][blank[i].x] = 1;
    vec[blank[j].y][blank[j].x] = 1;
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= M; j++) 
            visit[i][j] = false;
    int total = 0;

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            if(visit[i][j] == false && vec[i][j] == 2)
                total += bfs(i, j);
        }
    }
    if(answer < total) answer = total;
    vec[blank[i].y][blank[i].x] = 0;
    vec[blank[j].y][blank[j].x] = 0;     
}

int main(void) {
    int n;
    cin >> N >> M;
    int cnt = 0;
    for(int i = 1; i <= N; i++) {
        vec[i].push_back(0);
        for(int j = 1; j <= M; j++) {
            cin >> n;
            if(n == 0) {
                cnt++;
                blank.push_back({i, j});
            }
            vec[i].push_back(n);
        }
    }

    for(int i = 0; i < cnt; i++) 
        for(int j = i + 1; j < cnt; j++) 
            selectLocation(i, j);
    cout << answer << endl;
}