/*
  최대와 최소를 따로 구해주는 방식으로 구현


  부등호가 3개일 경우에는 9, 8, 7만 나오기 때문에 모든 수를 다 넣고 구할 필요가 없었다....
*/

#include<iostream>
#include<vector>
#include<string>
using namespace std;
bool visit[10] = { false, };
vector<char> pal;
int N;
string maximum = "", minimum = "";
void find_maximum(int depth, vector<int> vec){
    if(maximum != "") return;
    if(depth == pal.size()) {
        for(int i = 0; i < N + 1; i++)
            maximum += to_string(vec[i]);
        return ;
    }
    if(vec[0] == -1) {
        for(int i = 9; i >= 0; i--){
            visit[i] = true;
            vec[0] = i;
            find_maximum(depth + 1, vec);
            visit[i] = false;
        }
    } else {
        for(int i = 9; i >= 0; i--) {
            if(visit[i] == false){
                if(pal[depth] == '<' && vec[depth] < i) {
                    vec[depth + 1] = i;
                    visit[i] = true;
                    find_maximum(depth + 1, vec);
                    visit[i] = false;
                } else if(pal[depth] == '>' && vec[depth] > i) {
                    vec[depth + 1] = i;
                    visit[i] = true;
                    find_maximum(depth + 1, vec);
                    visit[i] = false;
                }
            }
        }
    }
}

void find_minimum(int depth, vector<int> vec){
    if(minimum != "") return;
    if(depth == pal.size()) {
        for(int i = 0; i < N + 1; i++)
            minimum += to_string(vec[i]);
        return ;
    }
    if(vec[0] == -1) {
        for(int i = 0; i < 10; i++){
            visit[i] = true;
            vec[0] = i;
            find_minimum(depth + 1, vec);
            visit[i] = false;
        }
    } else {
        for(int i = 0; i < 10; i++) {
            if(visit[i] == false){
                if(pal[depth] == '<' && vec[depth] < i) {
                    vec[depth + 1] = i;
                    visit[i] = true;
                    find_minimum(depth + 1, vec);
                    visit[i] = false;
                } else if(pal[depth] == '>' && vec[depth] > i) {
                    vec[depth + 1] = i;
                    visit[i] = true;
                    find_minimum(depth + 1, vec);
                    visit[i] = false;
                }
            }
        }
    }
}

int main(void){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> N;
    char c;
    for(int i = 0; i < N; i++){
        cin >> c;
        pal.push_back(c);
    }
    vector<int> vec(10, -1);
    find_maximum(-1, vec);
    fill(vec.begin(), vec.end(), -1);
    find_minimum(-1, vec);
    cout << maximum << "\n" << minimum << "\n";
    return 0;
}