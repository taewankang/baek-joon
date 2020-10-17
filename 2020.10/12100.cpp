//2048(Easy)
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N, answer;
struct Block {
    int value;
    bool isUnion;
};

void check(vector<vector<Block>> vec) {   //가장 큰 값을 찾아주는 함수
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            if(vec[i][j].value > answer) answer = vec[i][j].value;
        }
    }
}

vector<vector<Block>> reset(vector<vector<Block>> vec) {    //vector값 초기화
    for(int i =1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            vec[i][j].value = 0;
            vec[i][j].isUnion = false;
        }
    }
    return vec;
}

vector<vector<Block>> moveUp(vector<vector<Block>> vec) {   //위로 합치기
    vector<vector<Block>> temp(N + 1);
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            if(vec[i][j].value != 0) {
                if(temp[j].size() == 0) {   //i가 비어있다면
                    temp[j].push_back(vec[i][j]);
                } else {
                    if(temp[j][temp[j].size() - 1].isUnion == false && temp[j][temp[j].size() - 1].value == vec[i][j].value) {  //합친다.
                        temp[j][temp[j].size() - 1].value += vec[i][j].value;
                        temp[j][temp[j].size() - 1].isUnion = true;
                    } else {
                        temp[j].push_back(vec[i][j]);
                    }
                }
            }
        }
    }
    vec = reset(vec);
    for(int i = 1; i <= N; i++) {
        for(int j = 0; j < temp[i].size(); j++) {
            vec[j + 1][i].value = temp[i][j].value;
        }
    }
    return vec;
}

vector<vector<Block>> moveDown(vector<vector<Block>> vec) {     //아래로 합치기
    vector<vector<Block>> temp(N + 1);
    for(int i = N; i >= 1; i--) {
        for(int j = 1; j <= N; j++) {
            if(vec[i][j].value != 0) {
                if(temp[j].size() == 0) {
                    temp[j].push_back(vec[i][j]);
                } else {
                    if(temp[j][temp[j].size() - 1].isUnion == false && temp[j][temp[j].size() - 1].value == vec[i][j].value) {
                        temp[j][temp[j].size() - 1].value += vec[i][j].value;
                        temp[j][temp[j].size() - 1].isUnion = true;
                    } else {
                        temp[j].push_back(vec[i][j]);
                    }
                }
            }
        }
    }
    vec = reset(vec);
    for(int i = 1; i <= N; i++) {
        for(int j = 0; j < temp[i].size(); j++) {
            vec[N - j][i].value = temp[i][j].value;
        }
    }
    return vec;
}

vector<vector<Block>> moveRight(vector<vector<Block>> vec) {    //오른쪽으로 합치기
    vector<vector<Block>> temp(N + 1);
    for(int i = 1; i <= N; i++) {
        for(int j = N; j >= 1; j--) {
            if(vec[i][j].value != 0) {
                if(temp[i].size() == 0) {
                    temp[i].push_back(vec[i][j]);
                } else {
                    if(temp[i][temp[i].size() - 1].isUnion == false && temp[i][temp[i].size() - 1].value == vec[i][j].value) {
                        temp[i][temp[i].size() - 1].isUnion = true;
                        temp[i][temp[i].size() - 1].value += vec[i][j].value;
                    } else {
                        temp[i].push_back(vec[i][j]);
                    }
                } 
            }
        }
    }
    vec = reset(vec);
    for(int i = 1; i <= N; i++) {
        for(int j = 0; j < temp[i].size(); j++) {
            vec[i][N - j].value = temp[i][j].value;
        }
    }
    return vec;
}

vector<vector<Block>> moveLeft(vector<vector<Block>> vec) { //왼쪽으로 합치기
    vector<vector<Block>> temp(N + 1);
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            if(vec[i][j].value != 0) {
                if(temp[i].size() == 0) {
                    temp[i].push_back(vec[i][j]);
                } else {
                    if(temp[i][temp[i].size() - 1].isUnion == false && temp[i][temp[i].size() - 1].value == vec[i][j].value) {
                        temp[i][temp[i].size() - 1].isUnion = true;
                        temp[i][temp[i].size() - 1].value += vec[i][j].value;
                    } else {
                        temp[i].push_back(vec[i][j]);
                    }
                } 
            }
        }
    }
    vec = reset(vec);
    for(int i = 1; i <= N; i++) {
        for(int j = 0; j < temp[i].size(); j++) {
            vec[i][j + 1].value = temp[i][j].value;
        }
    }
    return vec;
}

void solve(vector<vector<Block>> map) {
    queue<pair<vector<vector<Block>>, int>> q;
    q.push({map, 0});
    while(!q.empty()) {
        vector<vector<Block>> block = q.front().first;
        int cnt = q.front().second;
        q.pop();
        if(cnt > 4) {
            check(block);
            continue;
        }
        vector<vector<Block>> temp;
        temp = moveUp(block);
        q.push({temp, cnt + 1});
        temp = moveDown(block);
        q.push({temp, cnt + 1});
        temp = moveLeft(block);
        q.push({temp, cnt + 1});
        temp = moveRight(block);
        q.push({temp, cnt + 1});
    }

}

int main(void) {
    cin >> N;
    int n;
    vector<vector<Block>> map(N + 1);
    for(int i = 1; i <= N; i++) {
        vector<Block> temp(N + 1);
        map[i] = temp;
    }
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++){
            cin >> n;
            map[i][j] = {n, false};
        }
    }
    solve(map);
    cout << answer << endl;
    return 0;
}