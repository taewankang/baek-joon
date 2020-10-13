#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int N, M, T;
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};
vector<vector<int>> map(101);
struct Gram{int y, x;};
Gram gram;

vector<vector<int>> bfs() {
    queue<pair<pair<int, int>, int>> q;
    vector<vector<int>> vec(N + 1);
    for(int i = 1; i <= N; i++) {
        vector<int> temp(M + 1, -1);
        vec[i] = temp;
    }
    vec[1][1] = 0;
    bool visit[101][101] = {false, };
    visit[1][1] = true;
    q.push({{1, 1}, 0});
    while(!q.empty()) {
        int y = q.front().first.first;
        int x = q.front().first.second;
        int cnt = q.front().second;
        // cout << y << " " << x << " " << cnt << endl;
        q.pop();
        for(int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 1 || ny > N || nx < 1 || nx > M || visit[ny][nx]) continue;
            if(map[ny][nx] == 0 || map[ny][nx] == 2) {
                visit[ny][nx] = true;
                vec[ny][nx] = cnt + 1;
                q.push({{ny, nx}, cnt + 1});
            }
        }
    }
    return vec;
}

int main(void){
    cin >> N >> M >> T;
    int n, answer = -1;
    for(int i = 1; i <= N; i++) {
        map[i].push_back(0);
        for(int j = 1; j <= M; j++) {
            cin >> n;
            if(n == 2) gram = {i, j};
            map[i].push_back(n);
        }
    }

    vector<vector<int>> vec = bfs();
    int gramDistance = vec[gram.y][gram.x];
    if(gramDistance == -1) { //그람까지 갈 수 없다면 
        if(vec[N][M] != -1) answer = vec[N][M];
    } else {    //갈 수 있다면
        if(vec[N][M] == -1) answer = vec[gram.y][gram.x] + (N - gram.y + M - gram.x); 
        else answer = min(vec[N][M], vec[gram.y][gram.x] + (N - gram.y + M - gram.x));
    }


    if(answer == -1 || answer > T) cout << "Fail\n";
    else cout << answer << endl;
    return 0;
}