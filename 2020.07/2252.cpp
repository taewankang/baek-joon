// 알고리즘 분류: 위상 정렬

#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int N, M;
vector<vector<int>> vec(32001);
vector<int> ordering(32001, 0);
vector<int> result;

void input(){
    cin >> N >> M;
    int front, back;
    for(int i = 0; i < M; i++){
        cin >> front >> back;
        vec[front].push_back(back);
        ordering[back]++;
    }
}

void topological(){
    queue<int> q;
    for(int i = 1; i <= N; i++){
        if(!ordering[i]) q.push(i);
    }
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        result.push_back(cur);
        for(int i = 0; i < vec[cur].size(); i++) {
            int next = vec[cur][i];
            ordering[next]--;
            if(ordering[next] == 0)
                q.push(next);
        }
    }
}

void show(){
    for(int i = 0; i < result.size(); i++)
        cout << result[i] << " ";
}

int main(void){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    input();
    topological();
    show();
    return 0;
}
