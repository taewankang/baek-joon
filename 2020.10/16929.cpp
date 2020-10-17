//Two Dots
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int N, M;
string answer = "No";
bool visit[51][51] = {false, };
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};
struct Start{int y, x;};
Start start;
vector<vector<int>> map(51);

void dfs(int y, int x, int depth) {
    if(answer == "Yes") return;
    for(int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 1 || ny > N || nx < 1 || nx > M) continue;
        if(map[ny][nx] != map[start.y][start.x]) continue;
        if(visit[ny][nx]) {
            if(depth >= 4 && start.y == ny && start.x == nx) {  //출발한 지점으로 돌아온다면 사이클이 만들어진 것
                answer = "Yes";
                return;
            }
        } else {
            visit[ny][nx] = true;
            dfs(ny, nx, depth + 1);
            visit[ny][nx] = false;
        }
    }
    return ;
}

int main(void){
    cin >> N >> M;
    char c;
    for(int i = 1; i <= N; i++) {
        map[i].push_back(' ');
        for(int j = 1; j <= M; j++) {
            cin >> c;
            map[i].push_back(c);
        }
    }

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++){
            start = {i, j};
            visit[i][j] = true;
            dfs(i, j, 1);
            visit[i][j] = false;
            if(answer == "Yes") break;
        }
    }
    cout << answer << endl;
    return 0;
}