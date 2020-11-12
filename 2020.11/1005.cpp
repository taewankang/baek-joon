#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
void tropo(vector<int> &time, vector<int> &cntEntry, vector<vector<int>> &map, int &start) {
    queue<int> q;
    vector<int> result(time.size(), 0);
    for(int i = 1; i < cntEntry.size(); i++) {
        if(cntEntry[i] == 0) {
            q.push(i);
            result[i] = time[i];
        }
    }

    while(!q.empty()) {
        int vertex = q.front();
        q.pop();
        for(int i = 0; i < map[vertex].size(); i++) {
            int next = map[vertex][i];
            result[next] = max(result[next], result[vertex] + time[next]);
            cntEntry[next]--;
            if(cntEntry[next] == 0) q.push(next);
        }
    }
    cout << result[start] << "\n";
}

void solve() {
    int N, K, start, end;
    cin >> N >> K;
    vector<int> time(N + 1, 0);
    vector<int> cntEntry(N + 1, 0);
    vector<vector<int>> map(N + 1);
    for(int i = 1; i <= N; i++) cin >> time[i];
    for(int i = 1; i <= K; i++) {
        cin >> start >> end;
        map[start].push_back(end);
        cntEntry[end]++;
    }
    cin >> start;
    tropo(time, cntEntry, map, start);
}

int main(void) {
    int T;
    cin >> T;
    for(int t = 0; t < T; t++) solve();
    return 0;
}