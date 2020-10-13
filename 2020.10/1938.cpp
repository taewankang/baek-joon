/*
  visit을 확인하기 위해서 중심점을 기준으로 확인을 해야 했다. 
  state도 함께 넣어서 확인할 수 있으면 더 좋을 듯
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N;
struct Tree {int y, x;};
struct Destination{ int y, x;};
vector<Destination> dest;
vector<vector<char>> vec(51);   //char형인거 조심하기
bool visit[2][51][51] = {false, };    //중심 좌표를 이용해서 visit을 확인해주기
int dy[4] = {1, -1, 0, 0};  //아래 위 오 왼
int dx[4] = {0, 0, 1, -1};
bool upPossible(vector<int> y, vector<int> x) {
    for(int i = 0; i < 3; i++) {
        int nextY = y[i] + dy[1];
        if(nextY < 1) return false;
        if(vec[nextY][x[i]] == '1') return false;
    }
    return true;
}

bool downPossible(vector<int> y, vector<int> x) {
    for(int i = 0; i < 3; i++) {
        int nextY = y[i] + dy[0];
        if(nextY > N) return false;
        if(vec[nextY][x[i]] == '1') return false;
    }
    return true;
}

bool leftPossible(vector<int> y, vector<int> x) {
    for(int i = 0; i < 3; i++) {
        int nextX = x[i] + dx[3];
        if(nextX < 1) return false;
        if(vec[y[i]][nextX] == '1') return false;
    }
    return true;
}

bool rightPossible(vector<int> y, vector<int> x) {
    for(int i = 0; i < 3; i++) {
        int nextX = x[i] + dx[2];
        if(nextX > N) return false;
        if(vec[y[i]][nextX] == '1') return false;
    }
    return true;
}

bool turnPossible(vector<int> y, vector<int> x) {
    int arr[3][3];
    int cenY = y[1];
    int cenX = x[1];
    if(cenY == 1 || cenY == N || cenX == 1 || cenX == N) return false;
    cenY--; cenX--;
    for(int i = 0; i < 3; i++) {    //9칸에 1이 있으면 돌릴 수 없다.
        for(int j = 0; j < 3; j++) {
            if(vec[cenY + i][cenX + j] == '1') return false;
        }
    }
    return true;
}

bool isSame(vector<int> y, vector<int> x) {
    for(int i = 0; i < 3; i++) 
        if(y[i] != dest[i].y || x[i] != dest[i].x) return false;
    return true;
}

int bfs(vector<Tree> vec) {
    queue<pair<vector<Tree>, int>> q;
    q.push({vec, 0});
    if(vec[0].y == vec[1].y) //가로 상태라면
      visit[0][vec[1].y][vec[1].x] = true; 
    else visit[1][vec[1].y][vec[1].x] = true;
    while(!q.empty()) {
        vector<int> y, x;
        for(int i = 0; i < 3; i++) {
            y.push_back(q.front().first[i].y);
            x.push_back(q.front().first[i].x);
        }
        int cnt = q.front().second;
        q.pop();
        if(isSame(y, x)) return cnt;
        if(upPossible(y, x)) {
            bool success = true;
            if(y[0] == y[1] && !visit[0][y[1] - 1][x[1]]) {    //가로 상태라면
                visit[0][y[1] - 1][x[1]] = true;
            } else if(x[0] == x[1] && !visit[1][y[1] - 1][x[1]]) {  //세로 상태라면
                visit[1][y[1] - 1][x[1]] = true;
            } else success = false;
            if(success) {
                vector<Tree> tree;
                for(int i =0 ; i < 3; i++)
                    tree.push_back({y[i] - 1, x[i]});
                q.push({tree, cnt + 1});
            }
        }
        if(downPossible(y, x)) {
            bool success = true;
            if(y[0] == y[1] && !visit[0][y[1] + 1][x[1]]) {    //가로 상태라면
                visit[0][y[1] + 1][x[1]] = true;
            } else if(x[0] == x[1] && !visit[1][y[1] + 1][x[1]]) {  //세로 상태라면
                visit[1][y[1] + 1][x[1]] = true;
            } else success = false;
            if(success) {
                vector<Tree> tree;
                for(int i = 0; i < 3; i++) 
                    tree.push_back({y[i] + 1, x[i]});
                q.push({tree, cnt + 1});
            }
        }
        if(leftPossible(y, x)) {
            bool success = true;
            if(y[0] == y[1] && !visit[0][y[1]][x[1] - 1]) {    //가로 상태라면
                visit[0][y[1]][x[1] - 1] = true;
            } else if(x[0] == x[1] && !visit[1][y[1]][x[1] - 1]) {  //세로 상태라면
                visit[1][y[1]][x[1] - 1] = true;
            } else success = false;
            if(success) {
                vector<Tree> tree;
                for(int i =0 ; i < 3; i++) 
                    tree.push_back({y[i], x[i] - 1});
                q.push({tree, cnt + 1});
            }
        }
        if(rightPossible(y, x)) {
            bool success = true;
            if(y[0] == y[1] && !visit[0][y[1]][x[1] + 1]) {    //가로 상태라면
                visit[0][y[1]][x[1] + 1] = true;
            } else if(x[0] == x[1] && !visit[1][y[1]][x[1] + 1]) {  //세로 상태라면
                visit[1][y[1]][x[1] + 1] = true;
            } else success = false;
            if(success) {
                vector<Tree> tree;
                for(int i =0 ; i < 3; i++) 
                    tree.push_back({y[i], x[i] + 1});
                q.push({tree, cnt + 1});            
            }
        }
        if(turnPossible(y, x)) {
            bool success = true;
            if(y[0] == y[1] && !visit[1][y[1]][x[1]]) {  //가로 상태라면
                y[0]--; x[0]++; y[2]++; x[2]--;
                visit[1][y[1]][x[1]] = true;
            } else if(x[0] == x[1] && !visit[0][y[1]][x[1]]) {    //세로 상태라면
                y[0]++; x[0]--; y[2]--; x[2]++;
                visit[0][y[1]][x[1]] = true;
            } else success = false;
            if(success) {
                vector<Tree> tree;
                for(int i = 0; i < 3; i++) tree.push_back({y[i], x[i]});
                q.push({tree, cnt + 1});
            }
        }
    }
    return 0;
}

int main(void){
    cin >> N;
    char c;
    vector<Tree> tree;
    
    for(int i = 1; i <= N; i++) {
        vec[i].push_back(' ');
        for(int j = 1; j <= N; j++) {
            cin >> c;
            if(c == 'B') {
                tree.push_back({i, j});
                vec[i].push_back('0');
            }
            else if(c == 'E') {
                dest.push_back({i, j});
                vec[i].push_back('0');
            } else vec[i].push_back(c);
        }
    }
    cout << bfs(tree) << "\n";
    return 0;
}