#include<iostream>
using namespace std;
int arr[1501][1501] = { 0, };
int pointer[1501] = { 0, };

int main(void){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++)
            cin >> arr[i][j];
    }

    fill(pointer, pointer + N + 1, N);
    for(int i = 1; i <= N; i++){    //N번째 수 찾기
        int maximum = -1000000001, x = 0;
        for(int j = 1; j <= N; j++){
            if(maximum < arr[pointer[j]][j]){
                maximum = arr[pointer[j]][j];
                x = j;
            }
        }
        pointer[x]--;
        if(i == N)
            cout << maximum << "\n";
    }
    return 0;
}