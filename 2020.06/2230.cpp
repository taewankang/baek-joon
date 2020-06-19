#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int N, M;
int main(void){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> N >> M;
    int n;
    vector<int> vec;
    for(int i = 0; i < N; i++){
        cin >> n;
        vec.push_back(n);
    }
    sort(vec.begin(), vec.end());

    int first = 0, last = 1, result = 2000000001;
    while(1){
        if(first == vec.size() - 2) break;
        int diff = vec[last] - vec[first];
        if(last == vec.size() - 1 && diff < M) break;
        if(diff >= M) {
            if(diff < result) result = diff;
            first++; 
        } else {
            if(last < vec.size()) last++;
        }  
    }
    cout << result << endl;
    return 0;
}
