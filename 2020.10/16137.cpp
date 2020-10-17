//견우와 직녀
#include <iostream>
#include <vector>
#include <queue>
#define INF 123456789
using namespace std;
int N, M;
vector < vector < int > > map(21);
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};
int answer = 123456789;
struct Data{
    int y, x;
    bool used;
};
void setBase() {    //오작교를 놓지 못하는 곳 찾기
    vector < vector < pair < int, int > > > check(21);
    for(int i = 1; i <= N; i++) {
        vector < pair < int, int > > temp(21, make_pair(0, 0));
        check[i] = temp;
    }
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            for(int k = 0; k < 2; k++) {
                int ny = i + dy[k];
                int nx = j + dx[k];
                if(ny < 1 || ny > N || nx < 1 || nx > N) continue;
                if(map[ny][nx] == 0) check[i][j].first++;
            }

            for(int k = 2; k < 4; k++) {
                int ny = i + dy[k];
                int nx = j + dx[k];
                if(ny < 1 || ny > N || nx < 1 || nx > N) continue;
                if(map[ny][nx] == 0) check[i][j].second++;                
            }
        }
    }

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            if(map[i][j] == 0 && check[i][j].first > 0 && check[i][j].second > 0) 
                map[i][j] = -1;
        }
    }
}

void bfs(int y, int x, bool used, int depth) {
    queue < pair < Data, int > > q;
    Data d = {1, 1, false};
    q.push(make_pair(d, 0));
    int visit[21][21];
    for(int i = 1; i <= N; i++) 
        for(int j = 1; j <= N; j++) 
            visit[i][j] = INF;
            
    visit[1][1] = 0;
    while(!q.empty()) {
        Data data = q.front().first;
        int cnt = q.front().second;
        q.pop();
        if(data.y == N && data.x == N) {
            if(answer > cnt) 
                answer = cnt;
        }
        for(int i = 0; i < 4; i++) {
            int ny = data.y + dy[i];
            int nx = data.x + dx[i];
            if(ny < 1 || ny > N || nx < 1 || nx > N) continue;
            if(map[ny][nx] == 1 && visit[ny][nx] > cnt) {
                d.y = ny; d.x = nx; d.used = false;
                q.push(make_pair(d, cnt + 1));
                visit[ny][nx] = cnt;
            } else if(map[ny][nx] > 1 && !data.used) {
                int idx = 1;
                while(1) {
                    if((cnt + idx) % map[ny][nx] == 0) break;
                    idx++;
                }
                if(visit[ny][nx] >= cnt + idx) {
                    d.y = ny; d.x = nx; d.used = true;
                    q.push(make_pair(d, cnt + idx));
                    visit[ny][nx] = cnt + idx;
                }
            }
        }
    }

}

int main(void) {
    cin >> N >> M;
    int n;
    for(int i = 1; i <= N; i++) {
        map[i].push_back(0);
        for(int j = 1; j <= N; j++) {
            cin >> n;
            map[i].push_back(n);
        }
    }

    setBase();
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            if(map[i][j] == 0) {
                map[i][j] = M;
                bfs(1, 1, false, 0);
                map[i][j] = 0;
            }
        }
    }
    cout << answer << endl;
    return 0;
}
