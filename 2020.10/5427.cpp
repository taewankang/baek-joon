/* 불 */
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};

vector<vector<char>> reset(int w, int h) {
    vector<vector<char>> vec(h + 2);
    vector<char> v(w + 2);
    for(int i = 0; i < vec.size(); i++)
        vec[i] = v;
    return vec;
}

void solve() {
    int w, h;
    cin >> w >> h;
    vector<vector<char>> map = reset(w, h);
    queue<pair<pair<int, int>, pair<int, char>>> q;
    int sangY, sangX;
    for(int i = 1; i <= h; i++) {
        for(int j = 1; j <= w; j++){
            cin >> map[i][j];
            if(map[i][j] == '@') {
                sangY = i; sangX = j;
            } else if(map[i][j] == '*') q.push({{i, j}, {0, '*'}});
        }
    }
    q.push({{sangY, sangX}, {0, '@'}});
    while(!q.empty()) {
        int y = q.front().first.first;
        int x = q.front().first.second;
        int time = q.front().second.first;
        char alpha = q.front().second.second;
        q.pop();
        for(int i = 0; i < 4; i++) {
            int nextY = y + dy[i];
            int nextX = x + dx[i];
            if(alpha == '*') {      //불이라면
                if(nextY < 1 || nextY > h || nextX < 1 || nextX > w || map[nextY][nextX] == '#' || map[nextY][nextX] == '*') continue;
                map[nextY][nextX] = '*';
                q.push({{nextY, nextX}, {time + 1, '*'}});
            } else if(alpha == '@') {
                if(nextY == 0 || nextY == h + 1 || nextX == 0 || nextX == w + 1) {
                    cout << time + 1 << endl;
                    return;
                } else if(map[nextY][nextX] == '.') {
                    map[nextY][nextX] = '@';
                    q.push({{nextY, nextX}, {time + 1, '@'}});
                }
            }
        }
    }
    cout << "IMPOSSIBLE\n";
}

int main(void){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    for(int i = 0; i < T; i++) solve();
    return 0;
}
