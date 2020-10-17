// 야구공(그림)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, answer, selected = 1;
vector<vector<int>> map(51);

int oneGame(vector<int> skill) {
    int outCnt = 0, point = 0;
    vector<int> arr(4, 0);
    while(outCnt < 3) { //3번 아웃이 될때까지 반복
        if(skill[selected] == 1) {  //안타
            if(arr[3] == 1) point++;
            arr[3] = arr[2];
            arr[2] = arr[1];
            arr[1] = 1;
        } else if(skill[selected] == 2) {   //2루타
            if(arr[3] == 1) point++;
            if(arr[2] == 1) point++;
            arr[3] = arr[1];
            arr[2] = 1;
            arr[1] = 0;
        } else if(skill[selected] == 3 || skill[selected] == 4) {   //3루타, 홈런
            for(int i = 1; i < 4; i++) {
                if(arr[i] == 1) point++;
                arr[i] = 0;
            }
            if(skill[selected] == 3) arr[3] = 1;
            else point++;
        } else if(skill[selected] == 0) outCnt++;   //아웃
        selected++;
        if(selected > 9) selected -= 9;
    }
    return point;
}

void gameStart(vector<int> list) {
    selected = 1;
    int round = 1; //몇번 타자인지 저장
    int point = 0;
    while(round <= N) {
        vector<int> skill;
        skill.push_back(0);
        for(int i = 1; i < 10; i++)
            skill.push_back(map[round][list[i]]);
        point += oneGame(skill);
        round++;
    }
    if(answer < point) answer = point;
    // 게임이 N이닝까지 종료
}

void peopleList(vector<int> people) {
    vector<int> list(10);
    int one, four;
    for(int i = 2; i <= 9; i++) {
        if(i > 4) list[i] = people[i];
        else list[i - 1] = people[i];
    }
    list[4] = 1;
    gameStart(list);
}

void game() {
    vector<int> people(10);
    for(int i = 2; i <= 9; i++) people[i] = i;
    do{
        peopleList(people);
    }while(next_permutation(people.begin() + 2, people.end()));
}

int main(void){
    cin >> N;
    int n;
    for(int i = 1; i <= N; i++) {
        map[i].push_back(0);
        for(int j = 1; j <= 9; j++) {
            cin >> n;
            map[i].push_back(n);
        }
    }

    game();
    cout << answer << endl;
    return 0;
}