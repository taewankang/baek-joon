#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, M, K;
vector<vector<int>> vec(51);
vector<vector<int>> rotation;
int answer = 123456789;
vector<vector<int>> start(vector<vector<int>> map, int y1, int x1, int y2, int x2) {
    int temp = map[y1][x1];
    for(int i = y1 + 1; i <= y2; i++) map[i - 1][x1] = map[i][x1];
    for(int i = x1 + 1; i <= x2; i++) map[y2][i - 1] = map[y2][i];
    for(int i = y2 - 1; i >= y1; i--) map[i + 1][x2] = map[i][x2];
    for(int i = x2 - 1; i > x1; i--) map[y1][i + 1] = map[y1][i];
    map[y1][x1 + 1] = temp;
    return map;
}

vector<vector<int>> rotate(vector<vector<int>> map, vector<int> v) {
    int y1 = v[0] - v[2];
    int x1 = v[1] - v[2];
    int y2 = v[0] + v[2];
    int x2 = v[1] + v[2];
    while(y1 < y2 && x1 < x2) {
        map = start(map, y1, x1, y2, x2);
        y1++;
        x1++;
        y2--;
        x2--;
    }
    return map;
}

void findMinimum(vector<vector<int>> map) {
    for(int i = 1; i <= N; i++) {
        int sum = 0;
        for(int j = 1; j <= M; j++)
            sum += map[i][j];
        if(answer > sum) answer = sum;
    }
}

void rotateStart(vector<int> visit) {
    vector<vector<int>> map = vec;
    for(int i = 0; i < visit.size(); i++)
        map = rotate(map, rotation[visit[i]]);
    findMinimum(map);
}

void permutation(vector<int> visit) {
    do{
        rotateStart(visit);
    }while(next_permutation(visit.begin(), visit.end()));
}

int main(void){
    int n;
    cin >> N >> M >> K;
    for(int i = 1; i <= N; i++) {
        vec[i].push_back(0);
        for(int j = 1; j <= M; j++) {
            cin >> n;
            vec[i].push_back(n);
        }
    }
    int a, b, c;
    vector<int> visit;
    for(int i =0; i < K; i++) {
        vector<int> v;
        visit.push_back(i);
        cin >> a >> b >> c;
        v.push_back(a);
        v.push_back(b);
        v.push_back(c);
        rotation.push_back(v);
    }
    permutation(visit);
    cout << answer << endl;
    return 0;
}