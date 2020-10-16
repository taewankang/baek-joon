// 다리 만들기2
// 크루스칼 알고리즘(union-find)
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
struct Start{int y, x;};
struct Bridge{int start, end, distance;};
vector < vector < int > > map(11);
vector < Bridge > bridge;
int N, M, answer;
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};
bool visit[11][11] = { false, };
Start start;
int root[8];
vector<bool> check(8, false);
bool compare(Bridge a, Bridge b) {
    return a.distance < b.distance;
}

void makeIsland(int y, int x, int cnt) {
    queue < pair < int, int > > q;
    q.push(make_pair(y, x));
    visit[y][x] = true;
    map[y][x] = cnt;
    while(!q.empty()) {
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++) {
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            if(ny < 1 || ny > N || nx < 1 || nx > M || visit[ny][nx]) continue;
            if(map[ny][nx] == -1) {
                map[ny][nx] = cnt;
                visit[ny][nx] = true;
                q.push(make_pair(ny, nx));
            }
        }
    }
}

Bridge makeBridge(int starting, int end, int distance) {
    Bridge b;
    b.start = starting;
    b.end = end;
    b.distance = distance;
    return b;
}

void findBridge(int starting, int y, int x) {
    int idx = 1;
    while(1) {  //위로 확인
        if(y - idx < 1) break;
        if(map[y - idx][x] == starting) break;
        else if(map[y - idx][x] == 0) idx++;
        else {
            bridge.push_back(makeBridge(starting, map[y - idx][x], idx - 1));
            break;
        }
    }
    idx = 1;
    while(1) {  //오른쪽으로 확인
        if(x + idx > M) break;
        if(map[y][x + idx] == starting) break;
        else if(map[y][x + idx] == 0) idx++;
        else {
            bridge.push_back(makeBridge(starting, map[y][x + idx], idx - 1));
            break;
        }
    }
}

int find(int node) {
    if(root[node] == node) return node;
    else return root[node] = find(root[node]);
    return 0;
}

void unionFunc(int x, int y) {
    x = find(x);
    y = find(y);
    if(x == y) return ;
    root[y] = x;
}

void kruskal() {
    for(int i = 0; i < bridge.size(); i++) {
        if(bridge[i].distance < 2) continue;
        int x = find(bridge[i].start);
        int y = find(bridge[i].end);
        if(x == y) continue; //이미 이어져 있는 상태라면 
        unionFunc(x, y);
        answer += bridge[i].distance;
    }
}

int main(void) {
    cin >> N >> M;
    int n;
    for(int i = 1; i <= N; i++) {
        map[i].push_back(0);
        for(int j = 1; j <= M; j++) {
            cin >> n;
            if(n == 1) {
                map[i].push_back(-1);
                start.y = i;
                start.x = j;
            }
            else map[i].push_back(n);
        }
    }

    int cnt = 1;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            if(map[i][j] == -1 && visit[i][j] == false) 
                makeIsland(i, j, cnt++);
        }
    }

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            if(map[i][j] != 0) findBridge(map[i][j], i, j);
        }
    }
    
    sort(bridge.begin(), bridge.end(), compare);
    for(int i = 1; i < cnt; i++) root[i] = i;
    
    kruskal();
    for(int i = 1; i < cnt; i++) {
        if(find(root[i]) != find(root[1])) {
            answer = -1;
            break;
        }
    }
    cout << answer << endl;
    return 0;
} 
