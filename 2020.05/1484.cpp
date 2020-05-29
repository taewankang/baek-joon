#include<iostream>
#include<math.h>
#include<vector>
using namespace std;
int main(void){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int G;
    cin >> G;
    int front = sqrt(G) + 1, last = 1;
    vector<int> vec;
    while(1) {
        int origin = front * front;
        int thinking = last * last;
        int diff = origin - thinking;
        if(front == 50001 && last == 50000) break;
        if(diff == G){
            vec.push_back(front);
            if(front != 50001) front++;
        } else if(diff < G) {   
            if(front != 50001) front++;
            else if(front == 50001) break;
        } else {
            last++;
        }
    }

    if(vec.size()) {
        for(int i = 0; i < vec.size(); i++)
            cout << vec[i] << "\n";
    } else cout << "-1\n";
    return 0;
}