/*돌다리 건너기*/
// https://jaimemin.tistory.com/525

#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<string> vec(2);
int dy[2] = {-1, 1};
int dx[2] = {1, 1};
string input;
int answer = 0;
int visit[2][101][21];
int dfs(int y, int x, int idx) {  
    if(idx == input.length()) return 1;
    if(visit[y][x][idx] != -1) return visit[y][x][idx];
    visit[y][x][idx] = 0;
    for(int i = x; i < vec[0].length(); i++){
        if(input[idx] == vec[1 - y][i]) 
            visit[y][x][idx] += dfs(1 - y, i + 1, idx + 1);
    }
    return visit[y][x][idx];
}

int main(void) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> input;
    cin >> vec[0] >> vec[1];
    for(int i =0; i < 2; i++) {
        for(int j = 0; j < 101; j++){
            for(int k = 0; k < 20; k++) visit[i][j][k] = -1;
        }
    }

    for(int i = 0; i < 2; i++)
        answer += dfs(i, 0, 0);
    cout << answer << endl;
    return 0;
}