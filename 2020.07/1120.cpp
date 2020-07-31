#include<iostream>
#include<string>
using namespace std;

int main(void){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    string A, B;
    cin >> A >> B;
    int diff = 0, min = 51;

    for(int i = 0; i <= B.length() - A.length(); i++){
        for(int j = 0; j < A.length(); j++)
            if(B[i + j] != A[j])
                diff++;
        min > diff ? min = diff: NULL;
        diff = 0;
    }
    cout << min << endl;
    return 0;
}