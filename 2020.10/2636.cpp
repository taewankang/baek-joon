// 치즈
/*
    가장 바깥에서부터 만나는 치즈들을 삭제해준다.
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct Start{int y, x;};
vector<vector<int>> map(101);
int N, M;
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};
Start start = {0, 0};

bool check() {
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) 
            if(map[i][j]) return false;
    }
    return true;
}

void erase() {
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) 
            if(map[i][j] == 2) map[i][j] = 0;
    }    
}

int cntCheese() {
    int cnt = 0;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) 
            if(map[i][j] == 1) cnt++;
    }        
    return cnt;
}

void bfs() {
    queue<pair<int, int>> q;
    bool visit[101][101] = {false, };
    visit[start.y][start.x] = true;
    q.push({start.y, start.x});
    while(!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++) {
            int nextY = y + dy[i];
            int nextX = x + dx[i];
            if(nextY < 1 || nextY > N || nextX < 1 || nextX > M || visit[nextY][nextX]) continue;
            if(map[nextY][nextX] == 0) {
                visit[nextY][nextX] = true;
                q.push({nextY, nextX});
            } else if(map[nextY][nextX] == 1) {
                visit[nextY][nextX] = true;
                map[nextY][nextX] = 2;
            }
        }
    }
}

void show() {
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) 
            cout << map[i][j] << " " ;
            cout << endl;
    }
}

int main(void){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> N >> M;
    int n;
    for(int i = 1; i <= N; i++) {
        map[i].push_back(0);
        for(int j = 1; j <= M; j++) {
            cin >> n;
            if(start.y == 0 && start.x == 0 && n == 0) {
                start.y = i;
                start.x = j;
            }
            map[i].push_back(n);
        }
    }
    int before, cnt = 0;
    while(1) {
        before = cntCheese();
        cnt++;
        bfs();
        erase();
        if(check()) break;
    }
    cout << cnt << "\n" << before << endl;

    return 0;
}