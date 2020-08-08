/*
    stack을 이용해서 짝을 이루는지 확인
    다음에 들어올 문자와 stack의 top에 있는 문자가 같으면 pop
    다르다면 push해준다.
*/
#include<iostream>
#include<string>
#include<stack>
using namespace std;

int isGoodWord(string str) {
    stack<char> s;
    s.push(str[0]);
    for(int i = 1; i < str.length(); i++){
        if(s.size()){
            if(s.top() == str[i]) s.pop();
            else s.push(str[i]);
        } else s.push(str[i]);
    }
    if(s.size()) return 0;
    return 1;
}

int main(void){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int N, answer = 0;
    cin >> N;
    string str;
    for(int i = 0; i < N; i++){
        cin >> str;
        answer += isGoodWord(str);
    }
    cout << answer << endl;
    return 0;
}