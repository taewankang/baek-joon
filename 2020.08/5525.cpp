/*
    O(M)으로 해결 하려고 시도.
    - 비교를 진행하다가 다른 값이 나온다 => 다른 인덱스 값부터 확인을 다시 시작한다.
    이 때 다른 인덱스 값을 i라고 할 때 M[i] 가 'I'라면 다음에 검색할 때는 M[i]부터 검색한다.
    반면 M[i]가 'O'라면 다음에 검색할 때는 M[i + 1]부터 검색한다. (M[i]가 'O'일 때부터 검색하도록 했더니
    무한 루프에 빠졌다..)
    - 비교한 값이 같으면 다음에 확인할 때는 다음 2개의 단어가 "OI"인지만 확인해주면 된다.
    1시간 15분 걸림..ㅠㅠ
*/
#include<iostream>
#include<string>
using namespace std;
int N, S, idx;
string P, M;

void makePn() {     //Pn을 만드는 함수
    for(int i = 0; i < 2 * N + 1; i++)
        i % 2 ? P += 'O': P += 'I';
}

bool isSame() {     //P와 M을 비교해준다.
    for(int i = idx; i < idx + P.length(); i++){
        if(P[i - idx] != M[i]) {
            M[i] == 'I' ? idx = i: idx = i + 1;
            return false;   
        }
    }
    idx += P.length() - 1;
    return true;
}

int main(void){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> N >> S;
    cin >> M;
    int result = 0;
    makePn();
    for(idx = 0; idx < S; ) {
        if(isSame()) {
            result++;
            while(1) {
                if(idx + 2 < S) {
                    if(M[idx + 1] == 'O' && M[idx + 2] == 'I') {
                        result++;   //앞에 값이 같으면 뒤에 오는 문자가 OI이면 연속되는 문자열도 같다.
                        idx += 2;
                    } else break;
                } else break;
            }
        }
    }
    cout << result << endl;
    return 0;
}