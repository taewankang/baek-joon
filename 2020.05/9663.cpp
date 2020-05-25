#include<iostream>
#include<algorithm>
using namespace std;
int N, result;
int map[16][16] = {0, };
bool is_possible(int y, int x){
    for(int i = 1; i < N; i++){
        if(map[y][i]) return false; //가로 검색
        if(map[i][x]) return false; //세로 검색
    }
    int i = y - 1, j = x - 1;    
    while(1){       //왼쪽 위 검색
        if(i < 1 || j < 1) break;
        if(map[i--][j--]) return false;
    }
    i = y - 1, j = x + 1;
    while(1){       //오른쪽 위 검색
        if(i < 1 || j > N) break;
        if(map[i--][j++]) return false;
    }
    i = y + 1, j = x - 1;
    while(1){       //오른쪽 아래 검색
        if(i > N || j < 0) break;
        if(map[i++][j--]) return false;
    }
    i = y + 1, j = x + 1;
    while(1){       //왼쪽 아래 검색
        if(i > N || j > N) break;
        if(map[i++][j++]) return false;
    }
    return true;
}

void dfs(int depth){
    if(depth == N + 1){
        result++;
        return;
    }
    
    for(int i = 1; i <= N; i++){
        if(!map[depth][i] && is_possible(depth, i)){
            map[depth][i] = true;
            dfs(depth + 1);
            map[depth][i] = false;
        }
    }
}

int main(void){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> N;
    dfs(1);
    cout << result << endl;
    return 0;
}