#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N, M;
vector<int> vec;
void recursive(vector<int> &v, int idx, int depth) {
    if(M == depth){
        return ;
    }

    for(int i = 0; i < N; i++) {
        v[depth] = vec[i];
        recursive(v, i, depth + 1);
    }
}

int main(void){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> N >> M;
    int n;
    for(int i = 0; i < N; i++){
        cin >> n;
        vec.push_back(n);
    }
    sort(vec.begin(), vec.end());

    vector<int> v(M, 0);
    for(int i = 0; i < N; i++){
        v[0] = vec[i];
        recursive(v, 1, 1);
    }

    return 0;
}
