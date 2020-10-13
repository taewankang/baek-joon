#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N, M;
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};
vector<vector<int>> map(101);

void outBfs() { //바깥쪽 부분을 -1로 초기화
    //시작 지점은 {1, 1}
    queue<pair<int, int>> q;
    bool visit[101][101] = {false, };
    visit[1][1] = true;
    q.push({1, 1});
    map[1][1] = -1;
    while(!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++) {
            int nextY = y + dy[i];
            int nextX = x + dx[i];
            if(nextY < 1 || nextY > N || nextX < 1 || nextX > M || visit[nextY][nextX]) continue;
            if(map[nextY][nextX] == 0) {
                map[nextY][nextX] = -1;
                visit[nextY][nextX] = true;
                q.push({nextY, nextX});
            }
        }
    }
}

void bfs() {    //치즈 안의 0부분을 2로 초기화
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) 
            if(map[i][j] == 0) map[i][j] = 2;
    }
}

void findCheese() {
    vector<vector<bool>> visit(N + 1);
    for(int i = 1; i <= N; i++) {
        vector<bool> temp(M + 1, false);
        visit[i] = temp;
    }

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            if(map[i][j] == 1) {
                int cnt = 0;
                for(int k = 0; k < 4; k++) {
                    int ny = i + dy[k];
                    int nx = j + dx[k];
                    if(ny < 1 || ny > N || nx < 1 || nx > M) continue;
                    if(map[ny][nx] == -1) cnt++;
                }
                if(cnt > 1) map[i][j] = 3;
            }
        }
    }
}

void resetCheese() {
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            if(map[i][j] == 3) map[i][j] = 0;
            else if(map[i][j] == 2) map[i][j] = 0;
            else if(map[i][j] == -1) map[i][j] = 0;
        }
    }
}

bool check() {
    for(int i = 1; i <= N; i++) 
        for(int j = 1; j <= M; j++) 
            if(map[i][j]) return false;
    return true;
}

void input() {
  int n;
  for(int i = 1; i <= N; i++) {
      map[i].push_back(0);
      for(int j = 1; j <= M; j++) {
          cin >> n;
          map[i].push_back(n);
      }
  }
}

int main(void){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> N >> M;
    int answer = 0;
    while(1) {
        outBfs();
        bfs();
        findCheese();
        resetCheese();
        answer++;
        if(check()) break;
    }
    cout << answer << endl;
    return 0;
}