#include<iostream>
using namespace std;
int N, M;
int root[1000001] = { 0, };

void reset(){
    for(int i = 0; i <= N; i++) root[i] = i;
}

int find(int x) {
    if(root[x] == x) return x;
    else return root[x] = find(root[x]);
}

void union_fun(int x, int y) {  
    x = find(x);    //수가 큰 노드 밑에 작은 노드가 오도록 해야 root가 섞이지 않는다.
    y = find(y);
    x > y ? root[x] = y: root[y] = x; 
}

int main(void){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int a, b, c;
    cin >> N >> M;
    reset();
    for(int i = 0; i < M; i++) {
        cin >> c >> a >> b;
        if(c == 0) union_fun(a, b);
        else find(a) == find(b)? cout << "YES\n": cout << "NO\n";
    }
    return 0;
}