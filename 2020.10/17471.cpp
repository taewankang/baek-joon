//게리맨더링
#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;
int people[11];
bool visit[11];
vector<vector<int>> vec(11);
int diff = 123456789;
int N, n;

bool bfs(vector<int> v, bool select) {
    queue<int> q;
    q.push(v[0]);
    bool check[11] = {false, };
    check[v[0]] = true;
    int cnt = 1;
    while(!q.empty()) {
        int first = q.front();
        if(cnt == v.size()) return true;
        q.pop();
        for(int i = 0; i < vec[first].size(); i++) {
            if(visit[vec[first][i]] == select && check[vec[first][i]] == false) {
                check[vec[first][i]] = true;
                q.push(vec[first][i]);
                cnt++;
            }
        }
    }
    return false;
}

void findDiff(vector<int> select, vector<int> nSelect) {
    int stotal = 0, ntotal = 0;
    for(auto iter: select) stotal += people[iter];
    for(auto iter: nSelect) ntotal += people[iter];
    if(abs(stotal - ntotal) < diff) diff = abs(stotal - ntotal);
}

void isConnect() {
    vector<int> select, nSelect;
    for(int i = 1; i <= N; i++) {
        if(visit[i]) select.push_back(i);
        else nSelect.push_back(i);
    }
    if(bfs(select, true) && bfs(nSelect, false)) findDiff(select, nSelect);
}

void permutation(int idx, int cnt) {
    if(cnt >= 1 && cnt < N) 
        isConnect();    //연결이 되어 있다면

    for(int i = idx; i <= N; i++) {
        if(visit[i]) continue;
        visit[i] = true;
        permutation(i, cnt + 1);
        visit[i] = false;
    }
}

int main(void){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> N;
    for(int i = 1; i <= N; i++) cin >> people[i];
    for(int i = 1; i <= N; i++) {
        cin >> n;
        for(int j = 0; j < n; j++) {
            int temp;
            cin >> temp;
            vec[i].push_back(temp);
            vec[temp].push_back(i);
        }
    }
    vector<int> acc;
    permutation(1, 0);
    if(diff == 123456789) diff = -1;
    cout << diff << endl;
    return 0;
}