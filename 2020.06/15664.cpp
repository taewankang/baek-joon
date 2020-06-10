#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
int N, M;
vector<int> vec;
set<vector<int>> s;
bool check[9] = { false, };
void recursive(vector<int> &v, int idx, int depth){
    if(depth == M) {
        s.insert(v);
        return;
    }

    for(int i = idx; i < N; i++){
        if(check[i]) continue;
        check[i] = true;
        v[depth] = vec[i];
        recursive(v, i, depth + 1);
        check[i] = false;
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

    for(int i = 0; i < N - M + 1; i++){
        v[0] = vec[i];
        check[0] = true;
        recursive(v, i + 1, 1);
        check[0] = false;
    }

    for(auto iter : s) {
        for(int i = 0; i < M; i++)
            cout << iter[i] << " ";
        cout << endl;
    }
    return 0;
}
