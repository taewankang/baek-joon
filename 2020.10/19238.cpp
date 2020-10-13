#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<vector<int>> map(21);
struct Taxi{int y, x, fuel;};
int answer = 0;
struct Customer{
    int py, px, dy, dx, distance, cnt;
    bool operator<(const Customer customer) const {
        if(distance > customer.distance) return true;
        else if(distance == customer.distance) {
            if(py > customer.py) return true;
            else if(py == customer.py) {
                if(px > customer.px) return true;
                return false;
            } else return false;
        } else return false;
    }
};
vector<Customer> customer;
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};
Taxi taxi;
int N, M, K;

vector<vector<int>> bfs() { //현재 택시 기준에서 각각의 인덱스에 대한 거리를 구해줌
    vector<vector<int>> temp = map;
    queue<pair<pair<int, int>, int>> q;
    q.push({{taxi.y, taxi.x}, 0});
    bool visit[21][21] = {false, };
    visit[taxi.y][taxi.x] = true;
    while(!q.empty()) {
        int y = q.front().first.first;
        int x = q.front().first.second;
        int dist = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++) {
            int nextY = y + dy[i];
            int nextX = x + dx[i];
            if(nextY < 0 || nextY >= N || nextX < 0 || nextX >= N || 
                visit[nextY][nextX] || temp[nextY][nextX] == -1) continue;
            visit[nextY][nextX] = true;
            q.push({{nextY, nextX}, dist + 1});
            temp[nextY][nextX] = dist + 1;
        }
    }
    return temp;
}

void except() {
    cout << "-1\n";
    exit(0);
}

int findCustomerDistance() {
    //손님한테 갈 수 없는 경우 => 거리가 0일 때
    vector<vector<int>> vec = bfs();
    priority_queue<Customer> pq;
    for(auto iter: customer) {
        if(iter.py != -1 && iter.px != -1) //작업이 끝난 손님이 아니라면
            pq.push({iter.py, iter.px, iter.dy, iter.dx, vec[iter.py][iter.px], iter.cnt});
    }

    if(pq.size() == 0) return -1;
    int shortest = vec[pq.top().py][pq.top().px];
    if((pq.top().py != taxi.y && pq.top().px != taxi.x) && shortest == 0) 
        except();  //택시 위치와 손님의 위치가 같지 않으면서 가려는 위치까지의 거리가 0이라면 => 못 가는 위치이다.
    taxi.fuel -= shortest;
    taxi.y = pq.top().py;
    taxi.x = pq.top().px;
    return pq.top().cnt;
}

void goDestination(int idx) {
    vector<vector<int>> temp = bfs();
    int dist = temp[customer[idx].dy][customer[idx].dx];
    if(dist == 0) except();    //목적지까지 갈 수 없다면
    taxi.y = customer[idx].dy;
    taxi.x = customer[idx].dx;
    taxi.fuel -= dist;
    customer[idx] = {-1, -1, -1, -1, 0, 0};
    if(taxi.fuel < 0) except();
    taxi.fuel += dist * 2;
}

int main(void){
    cin >> N >> M >> taxi.fuel;
    int n;
    for(int i = 0; i < N; i++) {    //map은 0부터 시작함
        for(int j = 0; j < N; j++) {
            cin >> n;
            if(n == 1) map[i].push_back(-1);
            else map[i].push_back(n);
        }
    }

    cin >> taxi.y >> taxi.x ;
    taxi.y--;
    taxi.x--;
    int a, b, c, d;
    for(int i = 0; i < M; i++) {
        cin >> a >> b >> c >> d;
        customer.push_back({a - 1, b - 1, c - 1, d - 1, 0, i});
    }
    while(1) {
        int customerIdx = findCustomerDistance();
        if(customerIdx == -1) break; 
        goDestination(customerIdx);
    }
    cout << taxi.fuel << endl;
    return 0;
}