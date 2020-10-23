#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> vec(100001);
int arr[100001] = {0, };

void dfs(int cnt) {
    for(int i = 0; i < vec[cnt].size(); i++) {
        if(arr[vec[cnt][i]] == 0) {
            arr[vec[cnt][i]] = cnt;
            dfs(vec[cnt][i]);
        }
    }
}

int main(void){
    int N, a, b;
    cin >> N;
    for(int i = 0; i < N - 1; i++) {
        cin >> a >> b;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }

    dfs(1);
    for(int i = 2; i <= N; i++) {
        cout << arr[i] << "\n";
    }
    return 0;
}