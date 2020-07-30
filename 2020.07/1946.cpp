#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(void){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int T, N;
    cin >> T;
    for(int t = 0; t < T; t++){
        vector<pair<int, int>> vec;
        int temp;
        int a, b, result = 1;
        cin >> N;
        for(int i = 0; i < N; i++) {
            cin >> a >> b;
            vec.push_back({ a, b });
        }
        sort(vec.begin(), vec.end());
        temp = vec[0].second;
        for(int i =1; i < vec.size(); i++){
            if(temp > vec[i].second){
                result++;
                temp = vec[i].second;
            }
        }
        cout << result << endl;
    }    
    return 0;
}