#include<iostream>
#include<vector>
using namespace std;
int N, M;
void recursive(vector<int> &vec, int depth){
    if(depth == M - 1){
        for(int i = 0; i < M; i++)
            cout << vec[i] << " ";
        cout << "\n";
        return ;
    }

    for(int i = vec[depth]; i <= N; i++){
        vec[depth + 1] = i;
        recursive(vec, depth + 1);
    }
}

int main(void){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> N >> M;
    vector<int> vec(M);
    for(int i = 1; i <= N; i++){
        vec[0] = i;
        recursive(vec, 0);
    }
    return 0;
}
