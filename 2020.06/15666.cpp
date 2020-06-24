#include <iostream> 
#include <vector> 
#include <algorithm> 
#include <set>
using namespace std; 
int N, M; 
vector<int> vec; 
    
void recursive(vector<int> &v, int idx, int depth){
    if(depth == M){
        for(int i = 0; i < v.size(); i++)
            cout << v[i] << " ";
        cout << "\n";
        return ;
    }

    for(int i = 0; i < vec.size(); i++){
        if(depth != 0 && v[depth - 1] > vec[i]) continue;
        v[depth] = vec[i];
        recursive(v, i, depth + 1);        
    }
}

int main(void) { 
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cin >> N >> M;
    set<int> s;
    int n;
    for(int i = 0; i < N; i++){
        cin >> n;
        s.insert(n);
    }

    for(auto iter : s)
        vec.push_back(iter);

    sort(vec.begin(), vec.end());
    vector<int> v(M, 0);
    recursive(v, 0, 0);
    return 0; 
}
