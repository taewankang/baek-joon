#include<iostream>
#include<vector>
#include<string>
using namespace std;
int N, K, answer;
bool alpha[26] = { false, };
vector<string> vec;

int readPossible(string str){
    for(int i = 0; i < str.length(); i++)
        if(!alpha[str[i] - 'a'])    //읽을 수 없는 문자열은 0을 반환
            return 0;
    return 1;   //읽을 수 있는 문자열은 1을 반환
}

void reset(){
    fill(alpha, alpha + 26, false);
    alpha['a' - 'a'] = true;    //인덱스 0
    alpha['n' - 'a'] = true;    //인덱스 13
    alpha['t' - 'a'] = true;    //인덱스 19
    alpha['i' - 'a'] = true;    //인덱스 8
    alpha['c' - 'a'] = true;    //인덱스 2
}

void permu(int idx, int cnt) {
    if(cnt == K - 5) {      //'a', 'n', 't', 'i', 'c'를 제외한 문자의 개수
        int temp = 0;
        for(int i = 0; i < vec.size(); i++)
            temp += readPossible(vec[i]);
        if(answer < temp) answer = temp;
        return ;
    }

    for(int i = idx; i < 26; i++){
        if(alpha[i]) continue;
        alpha[i] = true;
        permu(i, cnt + 1);
        alpha[i] = false;
    }
}

int main(void){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> N >> K;
    string str;
    if(K < 5) {     // 'a', 'n', 't', 'i', 'c'는 반드시 포함해야 한다.
        cout << "0" << endl;
        return 0;
    }

    for(int i = 0; i < N; i++){
        cin >> str;
        vec.push_back(str);
    }
    reset();        
    permu(0, 0);
    cout << answer  << endl;
    return 0;
}