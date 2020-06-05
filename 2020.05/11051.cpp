//nCk = (n-1)Ck + (n-1)C(k-1)를 사용한 DP를 이용해 구현
#include<iostream>
using namespace std;
int arr[1001][1001] = { 0, };
int N, K;
void reset(){
    for(int i = 0; i <= N; i++) arr[i][0] = 1;
}

int main(void){
    cin >> N >> K;
    reset();
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            arr[i][j] = (arr[i-1][j] + arr[i-1][j-1]) % 10007;
        }
    }

    cout << arr[N][K] << endl;
    return 0;
}