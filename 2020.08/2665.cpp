#include<iostream>
#include<vector>
#include<string>
#include<queue>
using namespace std;
#define MAX 50
bool map[MAX][MAX][MAX*MAX] = { false, };
struct Dir {int y, x;};
Dir dir[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
struct State {int y, x, cnt;};

struct cmp{
    bool operator()(State s1, State s2){
        return s1.cnt > s2.cnt;
    }
};

int main(void){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    string str;
    vector<string> vec;
    for(int i = 0; i < N; i++){
        cin >> str;
        vec.push_back(str);
    }
    priority_queue<State, vector<State>, cmp> pq;
    pq.push({0, 0, 0});
    while(!pq.empty()) {
        int y = pq.top().y;
        int x = pq.top().x;
        int cnt = pq.top().cnt;
        pq.pop();
        if(y == N - 1 && x == N - 1){
            cout << cnt << "\n";
            break;
        }

        for(int i = 0; i < 4; i++) {
            int nextY = y + dir[i].y;
            int nextX = x + dir[i].x;
            if(nextY < 0 || nextY >= N || nextX < 0 || nextX >= N)
                continue;
            int temp = cnt;
            if(vec[nextY][nextX] == '0') 
                temp++;
            if(map[nextY][nextX][temp]) continue;
            map[nextY][nextX][temp] = true;
            pq.push({nextY, nextX, temp});
        }
    }
    return 0;
}