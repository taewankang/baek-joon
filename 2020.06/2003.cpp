#include<iostream>
#include<vector>
using namespace std;
int N, M;
int main(void){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> N >> M;
    vector<int> vec;
    int n, result = 0;
    int front = 0, last = 0, sum = 0;

    for(int i = 0; i < N; i++){
        cin >> n;
        vec.push_back(n);
    }
    
    for( ; last < vec.size(); ){
        if(sum <= M){
            if(sum == M) result++;
            sum += vec[last++];
        } else {
            sum -= vec[front++];
        }
    }

    while(1){
        if(sum < M) break;
        if(sum == M) result++;
        sum -= vec[front++];
    }
    cout << result << endl;
    return 0;
}
