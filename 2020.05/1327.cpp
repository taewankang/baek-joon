#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<string>
#include<queue>
using namespace std;
map<string, bool> m;
string str = "", result = "";
int N, K;

int bfs(){
    queue<pair<string, int>> q;
    m.insert({str, 0});
    q.push({str, 0});
    while(!q.empty()){
        string s = q.front().first;
        int cnt = q.front().second;
        if(s == result) return cnt;
        q.pop();
        for(int i = 0; i <= str.length() - K; i++) {
            string temp = s;
            reverse(temp.begin() + i, temp.begin() + i + K);    //K개만큼 뒤집음
            if(m.find(temp) == m.end()) {        //찾지 못했다면
                m.insert({temp, true});
                q.push({temp, cnt + 1});
            } 
        }
    }
    return -1;
}

int main(void){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> N >> K;
    vector<int> vec;
    int n;
    for(int i = 0; i < N; i++){
        cin >> n;
        vec.push_back(n);        
        str += to_string(n);        
    }

    sort(vec.begin(), vec.end());
    for(int i = 0; i < vec.size(); i++)
        result += to_string(vec[i]);

    //result는 우리가 찾으려고 하는 문자열
    cout << bfs() << "\n";
    return 0;
}