#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> map(6);
vector<int> vec;
int answer = 0;
struct Mal { int y = 1, x = 0; };
int allMap[32] = {0, };
void makeMap() {
    //게임판 만들기
    //1번째: 0 2 4 6 8 10 12 14 16 18 20 22 24 26 28 30 32 34 36 38 40
    //2번째: 10 13 16 19 25 30 35 40
    //3번째: 20 22 24 25 30 35 40
    //4번째: 30 28 27 26 25 30 35 40
    //5번째: -1
    map[1].push_back(0);
    for(int i = 1; i <= 20; i++) map[1].push_back(2 * i);
    map[2].push_back(10); map[2].push_back(13); map[2].push_back(16); map[2].push_back(19);
    map[3].push_back(20); map[3].push_back(22); map[3].push_back(24);
    map[4].push_back(30); map[4].push_back(28); map[4].push_back(27); map[4].push_back(26);
    for(int i = 0; i < 4; i++) {
        map[2].push_back(25 + i * 5);
        map[3].push_back(25 + i * 5);
        map[4].push_back(25 + i * 5);
    }
    map[5].push_back(-1);
}

bool isDuplicate(int y, int x, int idx, Mal mal[]) {
    for(int i = 0; i < 4; i++)  //이동할 위치에 다른 말이 있는지 확인하는 함수
        if(idx != i && y == mal[i].y && x == mal[i].x) return true;
    for(int i = 0; i < 4; i++) {
        if(idx == i) continue;
        if(map[y][x] == 40 && map[mal[i].y][mal[i].x] == 40) return true;
        if(y == 1) {    //테두리를 돌때 같은 값이 있다면 이동하면 안된다.
            if(mal[i].y == 1 && mal[i].x == x) return true; 
        } else if(y > 1 && y < 5) {
            if(map[y][x] == 30) {   //파란색 30과 빨간색 30을 구별해서 확인해야 한다.
                if(x == 0) {    //파란색 칸인 30일 때
                    if(mal[i].y == 4 && mal[i].x == 0) return true;
                } else {    //빨간색 칸인 30일 때
                    if(mal[i].y == 2 && mal[i].x == 5) return true;
                    else if(mal[i].y == 3 && mal[i].x == 4) return true;
                    else if(mal[i].y == 4 && mal[i].x == 5) return true;
                }
            } else if(mal[i].y > 1 && map[y][x] == map[mal[i].y][mal[i].x]) return true;
        }
    }
    return false;
}

void recursive(Mal mal[], int idx, int total) {
    if(idx == 10) {
        if(total > answer) 
            answer = total;
        return ;
    }

    for(int i = 0; i < 4; i++) {
        Mal temp[4];
        for(int j = 0; j < 4; j++) temp[j] = mal[j];

        if(temp[i].y == 5 && temp[i].x == 0) continue;    //도착한 말이라면
        int y = temp[i].y;
        int x = temp[i].x;
        x += vec[idx];
        if(x >= map[y].size()) { //말이 도착했다.
            temp[i].y = 5;
            temp[i].x = 0;
            recursive(temp, idx + 1, total);
        } else if(y == 1 && x == 5) {   //10에 도착했다면
            temp[i].y = 2;
            temp[i].x = 0;
            if(isDuplicate(temp[i].y, temp[i].x, i, mal)) continue;
            recursive(temp, idx + 1, total + 10);
        } else if(y == 1 && x == 10) {  //20에 도착했다면
            temp[i].y = 3;
            temp[i].x = 0;
            if(isDuplicate(temp[i].y, temp[i].x, i, mal)) continue;
            recursive(temp, idx + 1, total + 20);
        } else if(y == 1 && x == 15) {  //30에 도착했다면
            temp[i].y = 4;
            temp[i].x = 0;
            if(isDuplicate(temp[i].y, temp[i].x, i, mal)) continue;
            recursive(temp, idx + 1, total + 30);
        } else {
            temp[i].x = x;
            if(isDuplicate(temp[i].y, temp[i].x, i, mal)) continue;
            recursive(temp, idx + 1, total + map[y][x]);
        }
    }
}

int main(void){
    int n;
    makeMap();
    for(int i = 0; i < 10; i++) {
        cin >> n;
        vec.push_back(n);
    }

    Mal mal[4];
    recursive(mal, 0, 0);
    cout << answer << endl;
    return 0;
}
