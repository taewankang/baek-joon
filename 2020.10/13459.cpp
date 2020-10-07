#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct Red{int y, x;};
struct Blue{int y, x;};
struct Goal{int y, x;};
struct Ball{
    Red red; 
    Blue blue;
};
bool redFinish = false, blueFinish = false;
Red startRed; Blue startBlue; Goal goal;
vector<vector<char>> reset(int N, int M) {
    vector<vector<char>> vec(N);
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            char c;
            cin >> c;
            if(c == 'R') {
                startRed.y = i;
                startRed.x = j;
                vec[i].push_back('.');
            } else if(c == 'B') {
                startBlue.y = i;
                startBlue.x = j;
                vec[i].push_back('.');
            } else if(c == 'O') {
                goal.y = i;
                goal.x = j;
                vec[i].push_back('O');
            } else vec[i].push_back(c);
        }
    }
    return vec;
}

bool errorCheck(Ball ball, int target) {
    if(ball.red.y == goal.y && ball.red.x == goal.x && 
        ball.blue.y == goal.y && ball.blue.x == goal.x) return false;
    else if(ball.red.y == goal.y && ball.red.x == goal.x) {
        cout << "1\n";
        exit(0);
    }
    else if(ball.blue.y == goal.y && ball.blue.x == goal.x) return false;
    else return true;
} 

Ball moveLeft(vector<vector<char>> vec, Ball ball) {
    if(ball.red.x > ball.blue.x) {   //파란색 먼저 움직이기
        while(1) {
            int y = ball.blue.y;
            int x = ball.blue.x;
            if(vec[y][x - 1] == '#') break;
            else if(vec[y][x - 1] == 'O') {
                ball.blue.x--;
                break;
            } else ball.blue.x--;
        }
        while(1) {
            int y = ball.red.y;
            int x = ball.red.x;
            if(vec[y][x - 1] == 'O') {
                ball.red.x--;
                break;
            } else if(vec[y][x - 1] == '#' || (ball.blue.y == y && ball.blue.x == x - 1)) break;
            else ball.red.x--;
        }
    } else {    //빨간색 먼저 움직이기
        while(1) {
            int y = ball.red.y;
            int x = ball.red.x;
            if(vec[y][x - 1] == '#') break;
            else if(vec[y][x - 1] == 'O') {
                ball.red.x--;
                break;
            } else ball.red.x--;
        }
        while(1) {
            int y = ball.blue.y;
            int x = ball.blue.x;
            if(vec[y][x - 1] == 'O') {
                ball.blue.x--;
                break;
            } else if(vec[y][x - 1] == '#' || (ball.red.y == y && ball.red.x == x - 1)) break;
            else ball.blue.x--;
        }
    }
    return ball;
}

Ball moveRight(vector<vector<char>> vec, Ball ball) {
    if(ball.red.x < ball.blue.x) {   //파란색 먼저 움직이기
        while(1) {
            int y = ball.blue.y;
            int x = ball.blue.x;
            if(vec[y][x + 1] == '#') break;
            else if(vec[y][x + 1] == 'O') {
                ball.blue.x++;
                break;
            } else ball.blue.x++;
        }
        while(1) {
            int y = ball.red.y;
            int x = ball.red.x;
            if(vec[y][x + 1] == 'O') {
                ball.red.x++;
                break;
            } else if(vec[y][x + 1] == '#' || (ball.blue.y == y && ball.blue.x == x + 1)) break;
            else ball.red.x++;
        }
    } else {    //빨간색 먼저 움직이기
        while(1) {
            int y = ball.red.y;
            int x = ball.red.x;
            if(vec[y][x + 1] == '#') break;
            else if(vec[y][x + 1] == 'O') {
                ball.red.x++;
                break;
            } else ball.red.x++;
        }
        while(1) {
            int y = ball.blue.y;
            int x = ball.blue.x;
            if(vec[y][x + 1] == 'O') {
                ball.blue.x++;
                break;
            } else if(vec[y][x + 1] == '#' || (ball.red.y == y && ball.red.x == x + 1)) break;
            else ball.blue.x++;
        }
    }
    return ball;
}

Ball moveTop(vector<vector<char>> vec, Ball ball) {
    if(ball.red.y > ball.blue.y) {  //파란색 먼저 움직이기
        while(1) {
            int y = ball.blue.y;
            int x = ball.blue.x;
            if(vec[y - 1][x] == '#') break;
            else if(vec[y - 1][x] == 'O') {
                ball.blue.y--;
                break;
            } else ball.blue.y--;
        }
        while(1) {
            int y = ball.red.y;
            int x = ball.red.x;
            if(vec[y - 1][x] == 'O') {
                ball.red.y--;
                break;
            } else if(vec[y - 1][x] == '#' || (ball.blue.y == y - 1 && ball.blue.x == x)) break;
            else ball.red.y--;
        }
    } else {    //빨간색 먼저 움직이기
        while(1) {
            int y = ball.red.y;
            int x = ball.red.x;
            if(vec[y - 1][x] == '#') break;
            else if(vec[y - 1][x] == 'O') {
                ball.red.y--;
                break;
            } else ball.red.y--;
        }
        while(1) {
            int y = ball.blue.y;
            int x = ball.blue.x;
            if(vec[y - 1][x] == 'O') {
                ball.blue.y--;
                break;
            } else if(vec[y - 1][x] == '#' || (ball.red.y == y - 1 && ball.red.x == x)) break;
            else ball.blue.y--;
        }
    }
    return ball;
}

Ball moveBottom(vector<vector<char>> vec, Ball ball) {
        if(ball.red.y < ball.blue.y) {  //파란색 먼저 움직이기
        while(1) {
            int y = ball.blue.y;
            int x = ball.blue.x;
            if(vec[y + 1][x] == '#') break;
            else if(vec[y + 1][x] == 'O') {
                ball.blue.y++;
                break;
            } else ball.blue.y++;
        }
        while(1) {
            int y = ball.red.y;
            int x = ball.red.x;
            if(vec[y + 1][x] == 'O') {
                ball.red.y++;
                break;
            } else if(vec[y + 1][x] == '#' || (ball.blue.y == y + 1 && ball.blue.x == x)) break;
            else ball.red.y++;
        }
    } else {    //빨간색 먼저 움직이기
        while(1) {
            int y = ball.red.y;
            int x = ball.red.x;
            if(vec[y + 1][x] == '#') break;
            else if(vec[y + 1][x] == 'O') {
                ball.red.y++;
                break;
            } else ball.red.y++;
        }
        while(1) {
            int y = ball.blue.y;
            int x = ball.blue.x;
            if(vec[y + 1][x] == 'O') {
                ball.blue.y++;
                break;
            } else if(vec[y + 1][x] == '#' || (ball.red.y == y + 1 && ball.red.x == x)) break;
            else ball.blue.y++;
        }
    }
    return ball;
}

int bfs(vector<vector<char>> vec) {
    queue<pair<Ball, int>> q;
    Ball ball = {startRed, startBlue};
    q.push({ball, 1});
    while(!q.empty()) {
        Ball ball = q.front().first;
        int cnt = q.front().second;
        if(cnt > 10) return 0;
        q.pop();
        Ball temp;
        temp = moveLeft(vec, ball);
        if(errorCheck(temp, cnt)) q.push({temp, cnt + 1});
        temp = moveRight(vec, ball);
        if(errorCheck(temp, cnt)) q.push({temp, cnt + 1});
        temp = moveTop(vec, ball);
        if(errorCheck(temp, cnt)) q.push({temp, cnt + 1});
        temp = moveBottom(vec, ball);
        if(errorCheck(temp, cnt)) q.push({temp, cnt + 1});
    }
    return 0;
}

int main(void) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int N, M;
    cin >> N >> M;
    vector<vector<char>> vec = reset(N, M);
    int result = bfs(vec);
    cout << result << endl;
    return 0;
}