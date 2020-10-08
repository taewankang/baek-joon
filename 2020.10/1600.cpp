//말이 되고픈 원숭이
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int K, W, H;
bool visit[31][201][201] = {false, };
struct Monkey{
    int y, x, movingCnt, k;
};
vector<vector<int>> vec(201);
vector<pair<int, int>> horse; 
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};
int answer = 0;
void input() {
    int n;
    cin >> K >> W >> H;
    for(int i = 1; i <= H; i++) {
        vec[i].push_back(0);
        for(int j = 1; j <= W; j++){
            cin >> n;
            vec[i].push_back(n);
        }
    }
}

void horseMoving() {
    horse.push_back({-1, -2});
    horse.push_back({1, -2});
    horse.push_back({2, -1});
    horse.push_back({2, 1});
    horse.push_back({1, 2});
    horse.push_back({-1, 2});
    horse.push_back({-2, 1});
    horse.push_back({-2, -1});
}


int bfs() {
    queue<Monkey> q;
    q.push({1, 1, 0, K});
    while(!q.empty()) {
        Monkey monkey = q.front();
        if(monkey.y == H && monkey.x == W) return monkey.movingCnt;
        q.pop();
        if(monkey.y < 1 || monkey.y > H || monkey.x < 1 || monkey.x > W || vec[monkey.y][monkey.x]) continue;
        if(visit[monkey.k][monkey.y][monkey.x]) continue;
        visit[monkey.k][monkey.y][monkey.x] = true;
        if(monkey.k) {
            for(int i = 0; i < 8; i++) {
                int nextY = monkey.y + horse[i].first;
                int nextX = monkey.x + horse[i].second;
                q.push({nextY, nextX, monkey.movingCnt + 1, monkey.k - 1});
            }
        }
        for(int i = 0; i < 4; i++) {
            int nextY = monkey.y + dy[i];
            int nextX = monkey.x + dx[i];
            q.push({nextY, nextX, monkey.movingCnt + 1, monkey.k});
        }   
    }
    return -1;
}

int main(void) {
    input();
    horseMoving();
    cout << bfs() << endl;
    return 0;
}