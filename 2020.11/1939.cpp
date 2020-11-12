#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<vector<pair<int, int>>> graph(100001);
int N, M, start, dest, maxWeight;
bool bfs(int mid) {
    queue<int> q;
    q.push(start);
    bool visit[100001] = {false, };
    visit[start] = true;
    while(!q.empty()) {
        int curVertex = q.front();
        if(curVertex == dest) return true;  //목적지에 도착했다면
        q.pop();
        for(int i = 0; i < graph[curVertex].size(); i++) {
            int nextVertex = graph[curVertex][i].first;
            int nextCost = graph[curVertex][i].second;
            if(visit[nextVertex] == false && mid <= nextCost) {
                q.push(nextVertex);
                visit[nextVertex] = true;
            }
        }
    }
    return false;
}

void solve() {
    int low = 0, high = maxWeight;
    while(low <= high) {
        int mid = (low + high) / 2;
        bfs(mid) ? low = mid + 1: high = mid - 1;
    }
    cout << high << endl;
}

int main(void) {
    int a, b, c;
    cin >> N >> M;
    for(int i = 0; i < M; i++) {
        cin >> a >> b >> c;
        graph[a].push_back({b, c}); //a에서 b까지 c무게를 옮길 수 있다.
        graph[b].push_back({a, c}); //b에서 a까지 c무게를 옮길 수 있다.
        if(maxWeight < c) maxWeight = c;
    }
    cin >> start >> dest;
    solve();

    return 0;
}