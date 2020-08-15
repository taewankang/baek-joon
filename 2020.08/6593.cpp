#include<iostream>
#include<string>
#include<vector>
#include<queue>
using namespace std;
#define MAX 30
vector<vector<string>> map;
int L, R, C;
struct Loc{int z, y, x, cnt;};
struct Dir{int y, x, z;};
Dir dir[6] = {{1, 0, 0}, {-1, 0, 0}, {0, 1, 0}, {0, -1, 0}, {0, 0, 1}, {0, 0, -1}};
Loc loc;
void input(){
    string str;
    cin >> L >> R >> C;
    if(L == 0 && R == 0 && C == 0) exit(0);
    for(int i = 0; i < L; i++){
        vector<string> vec;
        for(int j = 0; j < R; j++){
            cin >> str;
            vec.push_back(str);
            for(int k = 0; k < str.length(); k++){
                if(str[k] == 'S') {
                    loc.x = k;
                    loc.y = j;
                    loc.z = i;
                    loc.cnt = 0;
                }
            }
        }
        map.push_back(vec);
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    while(1){
        map.clear();
        input();
        int visit[MAX][MAX][MAX] = {0, };
        queue<Loc> q;
        q.push(loc);
        visit[loc.z][loc.y][loc.x] = true;
        bool success = false;
        while(!q.empty()) {
            int y = q.front().y;
            int x = q.front().x;
            int z = q.front().z;
            int cnt = q.front().cnt;
            q.pop();
            if(map[z][y][x] == 'E') {
                cout << "Escaped in " << cnt << " minute(s).\n";
                success = true;
                break;
            }
            for(int i = 0; i < 6; i++) {
                int nextZ = z + dir[i].z;
                int nextY = y + dir[i].y;
                int nextX = x + dir[i].x;
                if(nextZ < 0 || nextZ >= L || nextY < 0 || nextY >= R || nextX < 0 || nextX >= C) continue;
                if(visit[nextZ][nextY][nextX] == false && (map[nextZ][nextY][nextX] == '.' || map[nextZ][nextY][nextX] == 'E')) {
                    visit[nextZ][nextY][nextX] = true;
                    q.push({nextZ, nextY, nextX, cnt + 1});
                }
            }
        }
        if(!success) cout << "Trapped!\n";
    }
    return 0;
}