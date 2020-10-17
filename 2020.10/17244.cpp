// 아맞다우산
/*
    어떤 물건을 먼저 집고 나가야 적게 걷고 밖으로 나갈 수 있는가
*/
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int N, M;
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};
struct Person{int y, x;};
struct Stuff{int y, x;};
struct Goal{int y, x;};
Goal goal;
int answer = 987654321;
vector<vector<char>> map(51);

vector<vector<int>> bfs(Person person) {
    vector<vector<int>> vec(M + 1);
    for(int i = 1; i <= M; i++) {
        vector<int> v(N + 1, 0);
        vec[i] = v;
    }
    queue<pair<pair<int, int>, int>> q;
    q.push({{person.y, person.x}, 0});
    while(!q.empty()) {
        int y = q.front().first.first;
        int x = q.front().first.second;
        int cnt = q.front().second;
        q.pop();
        for(int i =0 ; i < 4; i++) {
            int nextY = y + dy[i];
            int nextX = x + dx[i];
            if(nextY < 1 || nextY > M || nextX < 1 || nextX > N || map[nextY][nextX] == '#') continue;
            if(nextY == person.y && nextX == person.x) continue;
            if((map[nextY][nextX] == '.' || map[nextY][nextX] == 'E') && vec[nextY][nextX] == 0){
                vec[nextY][nextX] = cnt + 1;
                q.push({{nextY, nextX}, cnt + 1});
            }
        }
    }
    return vec;
}

void findDistance(vector<int> vec, vector<Stuff> stuff, Person person) {
    int distance = 0;
    vector<vector<int>> m;
    for(int i = 0; i < vec.size(); i++) {
        m = bfs(person);
        distance += m[stuff[vec[i]].y][stuff[vec[i]].x];
        person.y = stuff[vec[i]].y;
        person.x = stuff[vec[i]].x;
    }
    m = bfs(person);
    distance += m[goal.y][goal.x];    
    if(answer > distance) answer = distance;
}

void permutation(Person person, vector<Stuff> stuff) {
    vector<int> vec;
    
    for(int i = 0; i < stuff.size(); i++) vec.push_back(i);
    do {
        Person temp = person;
        findDistance(vec, stuff, temp);
    }while(next_permutation(vec.begin(), vec.end()));
}

int main(void){
    char c;
    cin >> N >> M;
    Person person;
    vector<Stuff> stuff;
    for(int i = 1; i <= M; i++) {
        map[i].push_back(' ');
        for(int j = 1; j <= N; j++){
            cin >> c;
            if(c == 'S') person = {i, j};
            else if(c == 'X') stuff.push_back({i, j});
            else if(c == 'E') goal = {i, j};
            if(c == 'S' || c == 'X') map[i].push_back('.');
            else map[i].push_back(c);
        }
    }
    permutation(person, stuff);
    cout << answer << endl;
    return 0;
}