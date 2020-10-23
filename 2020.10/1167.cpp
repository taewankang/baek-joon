#include <iostream>
#include <vector>
#include <queue>
#define MAX 100001
using namespace std;
int N, answer = 0, idx = 0;
vector<vector<pair<int, int>>> vec(MAX);
void bfs(int n) {
    int arr[MAX] = {0, };
    bool visit[MAX] = {0, };
    queue<int> q;
    q.push(n);
    visit[n] = true;
    while(!q.empty()) {
        int start = q.front();
        q.pop();
        for(int i = 0; i < vec[start].size(); i++) {
            int dest = vec[start][i].first;
            int cost = vec[start][i].second;
            if(arr[dest] == 0 && visit[dest] == false) {
                arr[dest] = arr[start] + cost;
                visit[dest] = true;
                q.push(dest);
            }
        }
    }

    for(int i = 1; i <= N; i++) {
        if(answer < arr[i]) {
            answer = arr[i];
            idx = i;
        }
    }
}

int main(void){
    cin >> N;
    int n, a, b;
    for(int i = 1; i <= N; i++) {
        cin >> n;
        while(1) {
            cin >> a;
            if(a == -1) break;
            cin >> b;
            vec[n].push_back({a, b});
        }
    }
    bfs(1);
    answer = 0;
    bfs(idx);
    cout << answer << endl;
    return 0;
}