#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N, M;
vector<int> vec;
bool check[10001] = { false, };
void recursive(vector<int> &v, int idx, int depth){
    if(M == depth){
        for(int i = 0; i < M; i++)
            cout << v[i] << " ";
        cout << "\n";
        return ;
    }

    for(int i = 0; i < vec.size(); i++){
        if(check[vec[i]]) continue;
        check[vec[i]] = true;
        v[depth] = vec[i];
        recursive(v, i, depth + 1);
        check[vec[i]] = false;
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

    vector<int> v(vec.size(), 0);
    for(int i = 0; i < vec.size(); i++) {
        v[0] = vec[i];
        check[vec[i]] = true;
        recursive(v, 1, 1);
        check[vec[i]] = false;
    }
    return 0;
}
