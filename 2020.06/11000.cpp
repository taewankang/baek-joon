/*
    알고리즘 분류: 그리디
    사용 알고리즘: priority_queue
    걸린 시간: 1시간
    혼자 해결: X
*/

#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
int N;
vector<pair<int, int>> vec;

void input(){
    cin >> N;
    int start, finish;
    for(int i = 0; i < N; i++) {
        cin >> start >> finish;
        vec.push_back({start, finish});
    }
}

bool compare(pair<int, int> a, pair<int, int> b){
    if(a.first < b.first) return true;
    else if(a.first == b.first) {
        if(a.second < b.second) return true;
        return false;
    }
    return false;
}

int main(void){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    input();
    sort(vec.begin(), vec.end(), compare);
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(vec[0].second);
    for(int i = 1; i < N; i++){
        if(pq.top() <= vec[i].first)
            pq.pop();
        pq.push(vec[i].second);
    }
    cout << pq.size() << endl;
    return 0;
}