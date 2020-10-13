//로봇
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct Robot {int y, x, direction;};
struct Destination{int y, x, direction;};
int N, M;
Destination destination;
vector<vector<int>> map(101);
vector<vector<pair<int, int>>> moving(4);
int dy[5] = {0, 0, 0, 1, -1};
int dx[5] = {0, 1, -1, 0, 0};

vector<pair<int, int>> directionChange(int direction) {
    //회전할 수 있는 방향과 cost를 2차원 배열에 담아서 반환
    //2번 연속으로 회전하는 것은 불가
    vector<pair<int, int>> temp;
    if(direction == 1) {
        temp.push_back({3, 1});
        temp.push_back({4, 1});
    } else if(direction == 2) {
        temp.push_back({3, 1});
        temp.push_back({4, 1});
    } else if(direction == 3) {
        temp.push_back({1, 1});
        temp.push_back({2, 1});
    } else if(direction == 4) {
        temp.push_back({1, 1});
        temp.push_back({2, 1});
    }
    return temp;
}

int bfs(Robot starting) {
    queue<pair<Robot, int>> q;
    q.push({starting, 0});
    bool visit[5][101][101] = {false, };
    visit[starting.direction][starting.y][starting.x] = true;
    while(!q.empty()) {
        int y = q.front().first.y;
        int x = q.front().first.x;
        int direction = q.front().first.direction;
        int cnt = q.front().second;
        q.pop();
        if(y == destination.y && x == destination.x && direction == destination.direction) return cnt;
        vector<pair<int, int>> temp = directionChange(direction);
        for(int i = 0; i < temp.size(); i++) {
            if(!visit[temp[i].first][y][x]){
                q.push({{y, x, temp[i].first}, cnt + temp[i].second});
                visit[temp[i].first][y][x] = true;
            }
        }

        for(int i = 3; i >= 1; i--) { //바라보는 방향으로 전진하라
            int nextY = y + moving[i][direction].first;
            int nextX = x + moving[i][direction].second;
            if(nextY < 1 || nextY > N || nextX < 1 || nextX > M || 
                visit[direction][nextY][nextX] || map[nextY][nextX] == 1) continue;

            if(i > 1) {
                if(direction == 1 && (map[y][x + 1] == 1 || visit[direction][y][x + 1])) continue;
                else if(direction == 2 && (map[y][x - 1] == 1 || visit[direction][y][x - 1])) continue;
                else if(direction == 3 && (map[y + 1][x] == 1 || visit[direction][y + 1][x])) continue;
                else if(direction == 4 && (map[y - 1][x] == 1 || visit[direction][y - 1][x])) continue;
                if(i > 2) {
                    if(direction == 1 && (map[y][x + 2] == 1 || visit[direction][y][x + 2])) continue;
                    else if(direction == 2 && (map[y][x - 2] == 1 || visit[direction][y][x - 2])) continue;
                    else if(direction == 3 && (map[y + 2][x] == 1 || visit[direction][y + 2][x])) continue;
                    else if(direction == 4 && (map[y - 2][x] == 1 || visit[direction][y - 2][x])) continue;
                }
            } 
            q.push({{nextY, nextX, direction}, cnt + 1});
            visit[direction][nextY][nextX] = true;
        }
    }
    return 0;
}

void reset() {
    for(int i = 1; i < 4; i++) {
        moving[i].push_back({0, 0});
        for(int j = 1; j < 5; j++) 
            moving[i].push_back({dy[j] * i, dx[j] * i});
    }
}

Robot input() {
    cin >> N >> M;
    int n;
    for(int i = 1; i <= N; i++) {
        map[i].push_back(0);
        for(int j = 1; j <= M; j++) {
            cin >> n;
            map[i].push_back(n);
        }
    }
    Robot robot;
    cin >> robot.y >> robot.x >> robot.direction;
    cin >> destination.y >> destination.x >> destination.direction;
    return robot;
}

int main(void){
    reset();
    Robot robot = input();
    cout << bfs(robot) << "\n";    
    return 0;
}