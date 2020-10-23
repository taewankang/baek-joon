#include <iostream>
#include <vector>
using namespace std;
bool result = true;
vector<int> visit(20001);
vector<vector<int>> vec(20001);
vector<bool> check(20001);
void dfs(int cur) {
    for(int i = 0; i < vec[cur].size(); i++) {
        if(visit[vec[cur][i]] == 0) {   //아직 방문하지 않았다면
            if(visit[cur] == 1) {
                visit[vec[cur][i]] = -1;
                check[vec[cur][i]] = true;
                dfs(vec[cur][i]);
            }
            else if(visit[cur] == -1) {
                visit[vec[cur][i]] = 1; 
                check[vec[cur][i]] = true;
                dfs(vec[cur][i]);
            }
        } else {
            if(visit[cur] == 1 && visit[vec[cur][i]] == 1) {
                result = false;
                return ;
            } else if(visit[cur] == -1 && visit[vec[cur][i]] == -1) {
                result = false;
                return ;
            } else if(check[vec[cur][i]] == false) {
                check[vec[cur][i]] = true;
                dfs(vec[cur][i]);
            }
        }
    }
}
void solve() {
    int V, E, a, b;
    result = true;
    cin >> V >> E;
    for(int i = 0; i < E; i++) {
        cin >> a >> b;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }
    for(int i = 1; i <= V; i++) {
        if(visit[i] == 0) {
            visit[i] = 1;
            dfs(i);
        }
    }
    for(int j = 1; j <= V; j++) {
        visit[j] = 0;
        check[j] = false;
    }
    for(int i = 1; i <= V; i++) {
        vec[i].clear();        
    }

    if(result) cout << "YES\n";
    else cout << "NO\n";
}

int main(void){
    int T;
    cin >> T;
    for(int i = 0; i < T; i++) {
        solve();
    }

    return 0;
}